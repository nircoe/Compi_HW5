#include "code_generator.hpp"

string CodeGenerator::freshVar() {
    return "%var" + this->getCurrentReg(true);
}

string CodeGenerator::globalFreshVar() {
    return "@.var" + this->getCurrentReg(true);
}

ExpNode* CodeGenerator::arithmaticCalc(ExpNode &exp1, ExpNode &exp2, TypesEnum type, const string binop) {
    string binop_llvm = "";
    switch(binop[0]) {
        case '+':
            binop_llvm = "add";
            break;
        case '-':
            binop_llvm = "sub";
            break;
        case '*':
            binop_llvm = "mul";
            break;
        case '/':
            this->buffer->emit("call void @division_by_zero(i32 " + exp2.var + ")"); // need to add this function to llvm file
            if(type == TYPE_BYTE) binop_llvm = "udiv";
            else if(type == TYPE_INT) binop_llvm = "sdiv";
            else // error
            break;
        default:
            // error
            break;
    }
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
}


ExpNode* CodeGenerator::booleanCalc(ExpNode &exp1, ExpNode &exp2, const string relop) {
    // TODO: insert return statement here
}
