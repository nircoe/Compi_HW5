#include "code_generator.hpp"

string CodeGenerator::freshVar() {
    return "%var" + this->getCurrentReg(true);
}

string CodeGenerator::globalFreshVar() {
    return "@.var" + this->getCurrentReg(true);
}

string binopToLLVM(const char binop, CodeBuffer* buffer, TypesEnum type, ExpNode &exp2) {
    switch(binop) {
        case '+':
            return "add";
        case '-':
            return "sub";
        case '*':
            return "mul";
        case '/':
            buffer->emit("call void @division_by_zero(i32 " + exp2.var + ")"); // need to add this function to llvm file
            if(type == TYPE_BYTE) return "udiv";
            else if(type == TYPE_INT) return "sdiv";
    }
    return ""; // error
}

ExpNode* CodeGenerator::arithmaticCalc(ExpNode &exp1, ExpNode &exp2, TypesEnum type, const string binop) {
    string binop_llvm = binopToLLVM(binop[0], this->buffer, type, exp2);
    ExpNode* new_exp = new ExpNode(type, this->freshVar());
    new_exp->start_label = exp1.start_label;
    this->buffer->bpatch(exp1.next_list, exp2.start_label);
    this->buffer->bpatch(exp2.next_list, this->buffer->genLabel());

    this->buffer->emit(new_exp->var + " = " + binop_llvm + "i32 " + exp1.var + ", " + exp2.var);

    if (new_exp->type == TYPE_BYTE) {
        string temp = this->freshVar();
        this->buffer->emit(temp + " = and i32 " + new_exp->var + ", 255");
        new_exp->var = temp;
    }

    new_exp->next_list = this->buffer->makelist(
                            pair<int, BranchLabelIndex>(
                                this->buffer->emit("br label @"), FIRST));
    return new_exp;
}

string relopToLLVM(const string relop) {
    if(relop.compare("==") == 0) return "eq ";
    if(relop.compare("!=") == 0) return "ne ";
    if(relop.compare("<") == 0) return "lt ";
    if(relop.compare("<=") == 0) return "le ";
    if(relop.compare(">") == 0) return "gt ";
    if(relop.compare(">=") == 0) return "ge ";
    return ""; // error
}


ExpNode* CodeGenerator::booleanCalc(ExpNode &exp1, ExpNode &exp2, TypesEnum type, const string relop) {
    string relop_op = relopToLLVM(relop);

    if(!(relop.compare("==") == 0 || relop.compare("!=") == 0)) {
        if(exp1.type == TYPE_BYTE && exp2.type == TYPE_BYTE) relop_op = "u" + relop_op;
        else                                                 relop_op = "s" + relop_op;
    }

    string next_start_label = this->buffer->genLabel();
    ExpNode* new_exp = new ExpNode(type, this->freshVar());
    this->buffer->emit(new_exp->var + " = icmp " + relop_op + " i32 " + exp1.var + ", " + exp2.var);
    int next = this->buffer->emit("br i1 " + new_exp->var + ", label @, label @");
    new_exp->true_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
    new_exp->false_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, SECOND));
    new_exp->start_label = exp1.start_label;
    this->buffer->bpatch(exp1.next_list, exp2.start_label);
    this->buffer->bpatch(exp2.next_list, next_start_label);
    return new_exp;
}

ExpNode *CodeGenerator::processNot(ExpNode &exp)
{
    ExpNode* new_exp = new ExpNode(TYPE_BOOL);
    new_exp->true_list = exp.false_list;
    new_exp->false_list = exp.true_list;
    new_exp->start_label = exp.start_label;
    return new_exp;
}

ExpNode *CodeGenerator::processAnd(ExpNode &exp1, ExpNode &exp2)
{
    ExpNode* new_exp = new ExpNode(TYPE_BOOL);
    new_exp->start_label = exp1.start_label;
    this->buffer->bpatch(exp1.true_list, exp2.start_label);
    new_exp->true_list = exp2.true_list;
    new_exp->false_list = this->buffer->merge(exp1.false_list, exp2.false_list);
    return new_exp;
}

ExpNode *CodeGenerator::processOr(ExpNode &exp1, ExpNode &exp2)
{
    ExpNode* new_exp = new ExpNode(TYPE_BOOL);
    new_exp->start_label = exp1.start_label;
    this->buffer->bpatch(exp1.false_list, exp2.start_label);
    new_exp->true_list = this->buffer->merge(exp1.true_list, exp2.true_list);
    new_exp->false_list = exp2.false_list;
    return new_exp;
}

ExpNode *CodeGenerator::processTrueOrFalse(const bool isTrue) {
    ExpNode* new_exp = new ExpNode(TYPE_BOOL);
    new_exp->start_label = this->buffer->genLabel();
    int next =this->buffer->emit("br label @");
    List new_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
    if(isTrue) new_exp->true_list = new_list;
    else  new_exp->false_list = new_list;
    new_exp->value = isTrue ? "true" : "false";
    return new_exp;
}

void CodeGenerator::allocaVarsForFunc() {
    this->func_vars_arr = this->freshVar();
    this->buffer->emit(this->func_vars_arr + " = alloca [50 x i32]");
}

void CodeGenerator::storeVar(ExpNode &exp, StatementNode &sn, int offset) {
    List next_list = exp.next_list;
    if (exp.type == TYPE_BOOL){
        ExpNode* new_exp = makeBool(exp);
        exp.var = new_exp->var;
        next_list = new_exp->next_list;
    }
    string new_label = this->buffer->genLabel();
    this->buffer->bpatch(next_list, new_label);
    sn.start_label = exp.start_label;
    string var_ptr = this->freshVar();
    this->buffer->emit(var_ptr + " = getelementptr [50 x i32], [50 x i32]*" + this->func_vars_arr + ", i32 0, i32 " + std::to_string(offset));
    this->buffer->emit("store i32" + exp.var + ", i32*" + var_ptr);
    sn.next_list = this->buffer->makelist(pair<int,BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}


void CodeGenerator::initVar(IdNode& id, StatementNode &sn, TypesEnum type, int offset) {
    id.var = this->freshVar();
    string ptr = this->freshVar();
    sn.start_label = this->buffer->genLabel();
    if(type == TYPE_BYTE || type == TYPE_INT)
        this->buffer->emit(id.var + " = add i32 0, 0"); // init 0 
    else if(type == TYPE_BOOL) {
        string temp = this->freshVar();
        this->buffer->emit(temp + " = icmp eq i32 0, 1"); // init false, i1
        this->buffer->emit(id.var + " = zext i1 " + temp + " to i32"); // extend to i32
    }
    this->buffer->emit(ptr + " = getelementptr [50 x i32], [50 x i32]*" + this->func_vars_arr + ", i32 0, i32 " + std::to_string(offset));
    this->buffer->emit("store i32 " + id.var + ", i32* " + ptr);
    sn.next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::loadVar(ExpNode &exp, int offset) {
    exp.start_label = this->buffer->genLabel();
    if(offset >= 0) {
        exp.var = this->freshVar();
        string ptr = this->freshVar();
        this->buffer->emit(ptr + " = getelementptr [50 x i32], [50 x i32]*" + this->func_vars_arr + ", i32 0, i32 " + std::to_string(offset));
        this->buffer->emit(exp.var + " = load i32, i32* " + ptr);
    }
    else exp.var = "%" + std::to_string(offset);
    if(exp.type == TYPE_BOOL) {
        string is_true = this->freshVar();
        this->buffer->emit(is_true + " = icmp ne i32 " + exp.var + ", 0");
        int next = this->buffer->emit("br i1 " + is_true + ", label @, label @");
        exp.true_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
        exp.false_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, SECOND));
    }
    else exp.next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

string CodeGenerator::processNumAssign(ExpNode &exp, string var, string value) {
    string new_marker = this->buffer->genLabel();
    this->buffer->emit(var + " = add i32" + value + ", 0");
    int next = this->buffer->emit("br label @");
    exp.next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));    
    return new_marker;
}

ExpNode* CodeGenerator::makeBool(ExpNode &exp){
    if (exp.type != TYPE_BOOL) return new ExpNode(exp);
    
    ExpNode* new_exp = new ExpNode(TYPE_BOOL, this->freshVar());

    string true_dest = "TRUE_DEST" + std::to_string(this->current_label);
    string false_dest = "FALSE_DEST" + std::to_string(this->current_label);
    string next_dest = "NEXT_DEST" + std::to_string(this->current_label);
    current_label ++;

    this->buffer->emit(true_dest + ":");    
    int address_true = this->buffer->emit("br label@");
    this->buffer->emit(false_dest + ":");
    int address_false = this->buffer->emit("br label@");
    this->buffer->emit(next_dest + ":");
    
    List next_list = this->buffer->merge(this->buffer->makelist(pair<int, BranchLabelIndex>(address_true, FIRST)),
                               this->buffer->makelist(pair<int, BranchLabelIndex>(address_false, FIRST)));    

    ///backpatching holes
    this->buffer->bpatch(exp.true_list, true_dest);
    this->buffer->bpatch(exp.false_list, false_dest);
    this->buffer->bpatch(next_list, next_dest);
    
    this->buffer->emit(new_exp->var + " = phi i32 [1,%" + true_dest +"], [0, %" + false_dest + "]");
    int hole = this->buffer->emit("br label @");
    new_exp->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(hole, FIRST));
    return new_exp;
}

void CodeGenerator::startFunc(FuncDeclNode* func, int func_counter) {
    string args = "";
    int size = func->declarations.size();
    for(int i = 0; i < size; i++) {
        args += "i32";
        if(i != size - 1) args += ", ";
    }
    string _type = (func->type == TYPE_VOID) ? "void" : "i32";
    this->buffer->emit("define "+ _type + " @" + func->name + func_counter + "(" + args + ") {");
    this->allocaVarsForFunc();
}

void CodeGenerator::endFunc(RetTypeNode* type, StatementsNode* s, MarkerNode* marker) {
    this->buffer->bpatch(marker->next_list, s->start_label);
    string next_label = this->buffer->genLabel();
    this->buffer->bpatch(s->next_list, next_label);
    string ret_type = (type->type == TYPE_VOID) ? "void" : "i32 0";
    this->buffer->emit("ret " + ret_type + " }");
}

void CodeGenerator::processFirstStatement(StatementsNode* statements, StatementNode* statement) {
    statements->start_label = statement->start_label;
    statements->next_list = s->next_list;
    statements->break_list = statement->break_list;
    statements->continue_list = statement->continue_list;
}

void CodeGenerator::processStatements(StatementsNode* statements, StatementNode* new_statement) {
    this->buffer->bpatch(statements->next_list, s->start_label);
    statements->statements.push_back(new_statement);
    statements->next_list = s->next_list;
    statements->break_list = this->buffer->merge(statements->break_list, new_statement->break_list);
    statements->continue_list = this->buffer->merge(statements->continue_list, new_statement->continue_list);
}

void CodeGenerator::processEndStatement(StatementNode *statement, StatementsNode *statements) {
    statement->start_label = statements->start_label;
    statement->next_list = statements->next_list;
    statement->break_list = statements->break_list;
    statement->continue_list = statements->continue_list;
}

void CodeGenerator::processCall(CallNode *call, StatementNode *statement) {
    statement->start_label = call->start_label;
    statement->next_list = (call->type == TYPE_BOOL) ? 
                            this->buffer->merge(call->true_list, call->false_list) : call->next_list;
}

void CodeGenerator::processReturn(StatementNode *statement) {
    statement->start_label = this->buffer->genLabel();
    this->buffer->emit("ret void");
    statement->next_list = this->buffer->emit(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processReturn(StatementNode *statement, ExpNode *exp) {
    statement->start_label = exp->start_label;
    List next_list;
    if(exp->type == TYPE_BOOL) {
        ExpNode* temp = makeBool(*exp);
        exp->var = temp->var;
        next_list = temp->next_list;
    }
    else next_list = exp->next_list;
    string next_label = this->buffer->genLabel();
    this->buffer->emit("ret i32 " + exp->var);
    this->buffer->bpatch(next_list, next_label);
    statement->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void codeGenerator::processIf(StatementNode &new_statement, ExpNode &exp, StatementNode &statement){
    this->buffer->bpatch(exp.true_list, statement.start_label);
    new_statement.start_label = exp.start_label;
    new_statement.next_list = this->buffer->merge(exp.false_list, statement.next_list);
    new_statement.break_list = statement.break_list;
    new_statement.continue_list = statement.continue_list;
}