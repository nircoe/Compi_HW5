#include "code_generator.hpp"

void CodeGenerator::emitPrint(){

    this->buffer->emit("declare i32 @printf(i8*, ...)");
    this->buffer->emit("declare void @exit(i32)");
    this->buffer->emit("@.int_specifier = constant [4 x i8] c\"%d\\0A\\00\"");
    this->buffer->emit("@.str_specifier = constant [4 x i8] c\"%s\\0A\\00\"");
    this->buffer->emit("@.check_division_string = constant [23 x i8] c\"Error division by zero\\00\"");
    this->buffer->emit("");
    this->buffer->emit("define void @printi0(i32) {");
    this->buffer->emit("  %spec_ptr = getelementptr [4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0");
    this->buffer->emit("  call i32 (i8*, ...) @printf(i8* %spec_ptr, i32 %0)");
    this->buffer->emit("  ret void");
    this->buffer->emit("}");
    this->buffer->emit("");
    this->buffer->emit("define void @print0(i8*) {");
    this->buffer->emit("  %spec_ptr = getelementptr [4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0");
    this->buffer->emit("  call i32 (i8*, ...) @printf(i8* %spec_ptr, i8* %0)");
    this->buffer->emit("  ret void");
    this->buffer->emit("}");
    this->buffer->emit("");
    this->buffer->emit("define void @check_division(i32) {");
    this->buffer->emit("  %zero = icmp ne i32 %0, 0");
    this->buffer->emit("  br i1 %zero, label %true_label, label %false_label");
    this->buffer->emit("  true_label:");
    this->buffer->emit("      ret void");
    this->buffer->emit("  false_label:");
    this->buffer->emit("      %str = getelementptr [23 x i8], [23 x i8]* @.check_division_string, i32 0, i32 0");
    this->buffer->emit("      call void @print0(i8* %str)");
    this->buffer->emit("      call void @exit(i32 1)");
    this->buffer->emit("      ret void");
    this->buffer->emit("}");
    this->buffer->emit("");
}

string CodeGenerator::freshVar() {
    return "%var" + to_string(this->getCurrentReg(true));
}

string CodeGenerator::globalFreshVar() {
    return "@.var" + to_string(this->getCurrentReg(true));
}

string binopToLLVM(const char binop, CodeBuffer* buffer, TypesEnum type, ExpNode *exp2) {
    switch(binop) {
        case '+':
            return "add ";
        case '-':
            return "sub ";
        case '*':
            return "mul ";
        case '/':
            buffer->emit("call void @check_division(i32 " + exp2->var + ")"); // need to add this function to llvm file
            if(type == TYPE_BYTE) return "udiv ";
            else if(type == TYPE_INT) return "sdiv ";
    }
    return ""; // error
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

void CodeGenerator::allocaVarsForFunc() {
    this->func_vars_arr = this->freshVar();
    this->buffer->emit(this->func_vars_arr + " = alloca [50 x i32]");
}

void CodeGenerator::storeVar(ExpNode *exp, StatementNode *sn, int offset) {
    // List next_list = exp->next_list;
    if(exp->type == TYPE_BOOL) processBoolExp(exp);
    string new_label = this->buffer->genLabel();
    this->buffer->bpatch(exp->next_list, new_label);
    sn->start_label = exp->start_label;
    string var_ptr = this->freshVar();
    this->buffer->emit(var_ptr + " = getelementptr [50 x i32], [50 x i32]* " + this->func_vars_arr + ", i32 0, i32 " + to_string(offset));
    this->buffer->emit("store i32 " + exp->var + ", i32* " + var_ptr);
    sn->next_list = this->buffer->makelist(pair<int,BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}


void CodeGenerator::initVar(IdNode* id, StatementNode *sn, TypesEnum type, int offset) {
    id->var = this->freshVar();
    string ptr = this->freshVar();
    sn->start_label = this->buffer->genLabel();
    if(type == TYPE_BYTE || type == TYPE_INT)
        this->buffer->emit(id->var + " = add i32 0, 0"); // init 0 
    else if(type == TYPE_BOOL) {
        string temp = this->freshVar();
        this->buffer->emit(temp + " = icmp eq i32 0, 1"); // init false, i1
        this->buffer->emit(id->var + " = zext i1 " + temp + " to i32"); // extend to i32
    }
    this->buffer->emit(ptr + " = getelementptr [50 x i32], [50 x i32]* " + this->func_vars_arr + ", i32 0, i32 " + to_string(offset));
    this->buffer->emit("store i32 " + id->var + ", i32* " + ptr);
    sn->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::loadVar(ExpNode *exp, int offset) {
    exp->start_label = this->buffer->genLabel();
    if(offset >= 0) {
        exp->var = this->freshVar();
        string ptr = this->freshVar();
        this->buffer->emit(ptr + " = getelementptr [50 x i32], [50 x i32]* " + this->func_vars_arr + ", i32 0, i32 " + to_string(offset));
        this->buffer->emit(exp->var + " = load i32, i32* " + ptr);
    }
    else exp->var = "%" + to_string((offset + 1) * (-1));
    if(exp->type == TYPE_BOOL) {
        string is_true = this->freshVar();
        this->buffer->emit(is_true + " = icmp ne i32 " + exp->var + ", 0");
        int next = this->buffer->emit("br i1 " + is_true + ", label @, label @");
        exp->true_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
        exp->false_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, SECOND));
    }
    else exp->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

string CodeGenerator::processNumAssign(ExpNode &exp, string var, string value) {
    string new_marker = this->buffer->genLabel();
    this->buffer->emit(var + " = add i32" + value + ", 0");
    int next = this->buffer->emit("br label @");
    exp.next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));    
    return new_marker;
}

void CodeGenerator::startFunc(FuncDeclNode* func, int func_counter) {
    string args = "";
    int size = func->declarations.size();
    for(int i = 0; i < size; i++) {
        args += "i32";
        if(i != size - 1) args += ", ";
    }
    string _type = (func->type == TYPE_VOID) ? "void" : "i32";
    string count = to_string(func_counter);
    if (func->func_name.compare("main") == 0){
        count = "";
    }
    this->buffer->emit("define "+ _type + " @" + func->func_name + count + "(" + args + ") {");
    this->allocaVarsForFunc();
}

void CodeGenerator::endFunc(RetTypeNode* type, StatementsNode* s, MarkerNode* marker) {
    this->buffer->bpatch(marker->next_list, s->start_label);
    string next_label = this->buffer->genLabel();
    this->buffer->bpatch(s->next_list, next_label);
    string ret_type = (type->type == TYPE_VOID) ? "void" : "i32 0";
    this->buffer->emit("ret " + ret_type);
    this->buffer->emit("}");
}

void CodeGenerator::processFirstStatement(StatementsNode* statements, StatementNode* statement) {
    statements->start_label = statement->start_label;
    statements->next_list = statement->next_list;
    statements->break_list = statement->break_list;
    statements->continue_list = statement->continue_list;
}

void CodeGenerator::processStatements(StatementsNode* statements, StatementNode* new_statement) {
    this->buffer->bpatch(statements->next_list, new_statement->start_label);
    statements->statements.push_back(new_statement);
    statements->next_list = new_statement->next_list;
    statements->break_list = this->buffer->merge(statements->break_list, new_statement->break_list);
    statements->continue_list = this->buffer->merge(statements->continue_list, new_statement->continue_list);
}

void CodeGenerator::processEndStatement(StatementNode *statement, StatementsNode *statements) {
    statement->start_label = statements->start_label;
    statement->next_list = statements->next_list;
    statement->break_list = statements->break_list;
    statement->continue_list = statements->continue_list;
}

void CodeGenerator::processBoolExp(ExpNode *exp) {
    string true_label = this->buffer->genLabel(), true_var = this->freshVar();
    this->buffer->emit(true_var + " = zext i1 true to i32");
    int br_true = this->buffer->emit("br label @");
    string false_label = this->buffer->genLabel(), false_var = this->freshVar();
    this->buffer->emit(false_var + " = zext i1 false to i32");
    int br_false = this->buffer->emit("br label @");
    string next_label = this->buffer->genLabel();
    List true_list = this->buffer->makelist(pair<int, BranchLabelIndex>(br_true, FIRST));
    List false_list = this->buffer->makelist(pair<int, BranchLabelIndex>(br_false, FIRST));
    List next_list = this->buffer->merge(true_list, false_list);
    
    this->buffer->bpatch(exp->true_list, true_label);
    this->buffer->bpatch(exp->false_list, false_label);
    this->buffer->bpatch(next_list, next_label);
    exp->var = this->freshVar();
    this->buffer->emit(exp->var + " = phi i32 [1, %" + true_label + "], [0, %" + false_label + "]");
    exp->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processStatementCall(StatementNode *statement, CallNode *call) {
    statement->start_label = call->start_label;
    statement->next_list = (call->type == TYPE_BOOL) ? 
        this->buffer->merge(call->true_list, call->false_list) : 
        call->next_list;
}

void CodeGenerator::processCall(CallNode *call, vector<ExpNode*> exprs) {
    call->var = this->freshVar();
    int exprs_size = exprs.size();
    call->start_label = exprs[exprs_size - 1]->start_label;
    string emit_args = "", next_label;
    int br_next;
    for(int i = exprs_size - 1; i >= 0; --i) {
        next_label = (i == 0) ? this->buffer->genLabel() : exprs[i - 1]->start_label;
        if(i == 0) br_next = this->buffer->emit("br label @");
        if(exprs[i]->type == TYPE_STRING) {
            emit_args += "i8* " + exprs[i]->var;
            if(i > 0) emit_args += ", ";
        }
        else {
            if(exprs[i]->type == TYPE_BOOL) {
                processBoolExp(exprs[i]);
            }
            emit_args += "i32 " + exprs[i]->var;
            if(i > 0) emit_args += ", ";
        }
        this->buffer->bpatch(exprs[i]->next_list, next_label);
    }

    string label = this->buffer->genLabel();
    List next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(br_next, FIRST));
    this->buffer->bpatch(next_list, label);
    if(call->type == TYPE_VOID) this->buffer->emit("call void @" + call->name + to_string(call->counter) + "(" + emit_args + ")");
    else this->buffer->emit(call->var + " = call i32 @" + call->name + to_string(call->counter) + "(" + emit_args + ")");

    int br_call;
    if(call->type == TYPE_BOOL) {
        string bool_var = this->freshVar();
        this->buffer->emit(bool_var + " = icmp ne i32 0, " + call->var);
        call->var = bool_var;
        br_call = this->buffer->emit("br i1 " + call->var + ", label @, label @");
        call->true_list = this->buffer->makelist(pair<int, BranchLabelIndex>(br_call, FIRST));
        call->false_list = this->buffer->makelist(pair<int, BranchLabelIndex>(br_call, SECOND));
    }
    else {
        br_call = this->buffer->emit("br label @");
        call->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(br_call, FIRST));
    }

}

void CodeGenerator::processReturn(StatementNode *statement) {
    statement->start_label = this->buffer->genLabel();
    this->buffer->emit("ret void");
    statement->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processReturn(StatementNode *statement, ExpNode *exp) {
    statement->start_label = exp->start_label;
    List next_list;
    if(exp->type == TYPE_BOOL) processBoolExp(exp);
    else next_list = exp->next_list;
    string next_label = this->buffer->genLabel();
    this->buffer->emit("ret i32 " + exp->var);
    this->buffer->bpatch(next_list, next_label);
    statement->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processIfElse(StatementNode *new_statement, ExpNode *exp, StatementNode *if_statement, StatementNode *else_statement) {
    this->buffer->bpatch(exp->true_list, if_statement->start_label);
    new_statement->start_label = exp->start_label;
    if(else_statement) { // if else
        this->buffer->bpatch(exp->false_list, else_statement->start_label);
        new_statement->break_list = this->buffer->merge(if_statement->break_list, else_statement->break_list);
        new_statement->continue_list = this->buffer->merge(if_statement->continue_list, else_statement->continue_list);
        new_statement->next_list = this->buffer->merge(if_statement->next_list, else_statement->next_list);
    }
    else { // only if
        new_statement->break_list = if_statement->break_list;
        new_statement->continue_list = if_statement->continue_list;
        new_statement->next_list = this->buffer->merge(exp->false_list, if_statement->next_list);
    }
}

void CodeGenerator::processWhile(StatementNode *new_statement, ExpNode *exp, StatementNode *statement) {
    new_statement->start_label = exp->start_label;
    this->buffer->emit("br label %" + new_statement->start_label);
    this->buffer->bpatch(statement->next_list, new_statement->start_label);
    this->buffer->bpatch(statement->continue_list, new_statement->start_label);
    this->buffer->bpatch(exp->true_list, statement->start_label);
    new_statement->next_list = this->buffer->merge(exp->false_list, statement->break_list);
}

void CodeGenerator::processNot(ExpNode *new_exp, ExpNode *exp) {
    new_exp->true_list = exp->false_list;
    new_exp->false_list = exp->true_list;
    new_exp->start_label = exp->start_label;
}

void CodeGenerator::processAnd(ExpNode *new_exp, ExpNode *exp1, ExpNode *exp2) {
    new_exp->start_label = exp1->start_label;
    this->buffer->bpatch(exp1->true_list, exp2->start_label);
    new_exp->true_list = exp2->true_list;
    new_exp->false_list = this->buffer->merge(exp1->false_list, exp2->false_list);
}

void CodeGenerator::processOr(ExpNode *new_exp, ExpNode *exp1, ExpNode *exp2) {
    new_exp->start_label = exp1->start_label;
    this->buffer->bpatch(exp1->false_list, exp2->start_label);
    new_exp->true_list = this->buffer->merge(exp1->true_list, exp2->true_list);
    new_exp->false_list = exp2->false_list;
}

void CodeGenerator::processTrueOrFalse(ExpNode *new_exp, const bool isTrue) {
    new_exp->start_label = this->buffer->genLabel();
    int next = this->buffer->emit("br label @");
    List new_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
    if(isTrue) new_exp->true_list = new_list;
    else       new_exp->false_list = new_list;
    new_exp->value = isTrue ? "true" : "false";
}

void CodeGenerator::processBreakContinue(StatementNode *statement, bool isBreak) {
    statement->start_label = this->buffer->genLabel();
    if(isBreak) {
        statement->break_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
        statement->isBreak = true;
        return;
    }
    statement->continue_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processParentheses(ExpNode *new_exp, ExpNode *exp) {
    new_exp->var = exp->var;
    new_exp->true_list = exp->true_list;
    new_exp->false_list = exp->false_list;
    new_exp->next_list = exp->next_list;
    new_exp->start_label = exp->start_label;
    new_exp->value = exp->value;
}

void CodeGenerator::processBinop(ExpNode *new_exp, ExpNode *exp1, ExpNode *exp2, const char binop) {
    new_exp->start_label = exp1->start_label;
    this->buffer->bpatch(exp1->next_list, exp2->start_label);
    this->buffer->bpatch(exp2->next_list, this->buffer->genLabel());
    string binop_llvm = binopToLLVM(binop, this->buffer, new_exp->type, exp2);

    this->buffer->emit(new_exp->var + " = " + binop_llvm + "i32 " + exp1->var + ", " + exp2->var);

    if (new_exp->type == TYPE_BYTE) {
        string temp = this->freshVar();
        this->buffer->emit(temp + " = and i32 " + new_exp->var + ", 255");
        new_exp->var = temp;
    }

    new_exp->next_list = this->buffer->makelist(
                            pair<int, BranchLabelIndex>(
                                this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processRelop(ExpNode *new_exp, ExpNode *exp1, ExpNode *exp2, const string relop) {
    string relop_op = relopToLLVM(relop);

    if(!(relop.compare("==") == 0 || relop.compare("!=") == 0)) {
        if(exp1->type == TYPE_BYTE && exp2->type == TYPE_BYTE) relop_op = "u" + relop_op;
        else                                                 relop_op = "s" + relop_op;
    }

    string next_start_label = this->buffer->genLabel();
    this->buffer->emit(new_exp->var + " = icmp " + relop_op + " i32 " + exp1->var + ", " + exp2->var);
    int next = this->buffer->emit("br i1 " + new_exp->var + ", label @, label @");
    new_exp->true_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
    new_exp->false_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, SECOND));
    new_exp->start_label = exp1->start_label;
    this->buffer->bpatch(exp1->next_list, exp2->start_label);
    this->buffer->bpatch(exp2->next_list, next_start_label);
}

void CodeGenerator::processExpCall(ExpNode *exp, CallNode *call) {
    exp->start_label = call->start_label;
    exp->true_list = call->true_list;
    exp->false_list = call->false_list;
    exp->next_list = call->next_list;
    exp->value = call->name;
    exp->var = call->var;
}

void CodeGenerator::processExpNum(ExpNode *exp, NumNode *num) {
    exp->value = num->num_val;
    exp->start_label = this->buffer->genLabel();
    this->buffer->emit(exp->var + " = add i32 " + exp->value + ", 0");
    exp->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processExpString(ExpNode *exp, StringNode *string_node) {
    string global_var = this->globalFreshVar();
    string str = string_node->str;
    exp->value = str;
    str.pop_back();
    int str_len = str.length();
    str = "c" + str + "\\00";
    string llvm_size = "[" + to_string(str_len)  + " x i8]";
    this->buffer->emitGlobal(global_var + " = constant " + llvm_size + " " + str + "\"");
    exp->start_label = this->buffer->genLabel();
    string global_var_temp = global_var;
    std::replace(global_var.begin(), global_var.end(), '@', '%');
    exp->var =global_var;
    this->buffer->emit(exp->var + " = getelementptr " + llvm_size + ", " + llvm_size + "* " + global_var_temp + ", i32 0, i32 0");
    exp->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
}

void CodeGenerator::processConvertion(ExpNode *new_exp, ExpNode *exp) {
    new_exp->start_label = exp->start_label;
    new_exp->value = exp->value;    
    if(new_exp->type == TYPE_BYTE && exp->type == TYPE_INT) {
        string next_label = this->buffer->genLabel();
        this->buffer->bpatch(exp->next_list, next_label);
        this->buffer->emit(new_exp->var + " = and i32 " + exp->var + ", 255");
        new_exp->next_list = this->buffer->makelist(pair<int, BranchLabelIndex>(this->buffer->emit("br label @"), FIRST));
    }
    else {
        this->buffer->emit(new_exp->var + " = add i32 " + exp->var + ", 0");
        new_exp->next_list = exp->next_list;
    }
}
