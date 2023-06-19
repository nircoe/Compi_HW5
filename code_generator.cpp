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
    ExpNode* new_exp = new ExpNode(TYPE_BOOL, this->freshVar());
    new_exp->start_label = exp1.start_label;
    this->buffer->bpatch(exp1.true_list, exp2.start_label);
    new_exp->true_list = exp2.true_list;
    new_exp->false_list = this->buffer->merge(exp1.false_list, exp2.false_list);
    return new_exp;
}

ExpNode *CodeGenerator::processOr(ExpNode &exp1, ExpNode &exp2)
{
    ExpNode* new_exp = new ExpNode(TYPE_BOOL, this->freshVar());
    this->buffer->bpatch(exp1.false_list, exp2.start_label);
    new_exp->true_list = this->buffer->merge(exp1.true_list, exp2.true_list);
    new_exp->false_list = exp2.false_list;
    new_exp->start_label = exp1.start_label;
    return new_exp;
}

ExpNode *CodeGenerator::processTrueOrFalse(const bool isTrue) {
    ExpNode* new_exp = new ExpNode(TYPE_BOOL, this->freshVar());
    new_exp->start_label = this->buffer->genLabel();
    int next =this->buffer->emit("br label @");
    List new_list = this->buffer->makelist(pair<int, BranchLabelIndex>(next, FIRST));
    if(isTrue) new_exp->true_list = new_list;
    else  new_exp->false_list = new_list;
    new_exp->value = isTrue ? "true" : "false";
    return new_exp;
}
