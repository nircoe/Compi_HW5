#ifndef CODE_GENERATOR_HPP
#define CODE_GENERATOR_HPP

#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include "bp.hpp"
#include "types.hpp"

using std::string;
using std::stack;
using std::queue;

class CodeGenerator {
    CodeBuffer* buffer;
    int current_reg;
    int current_label;

    public:

        CodeGenerator(CodeBuffer* _buffer) : buffer(_buffer), current_reg(0) {};
        
        CodeBuffer* getCodeBuffer() { return buffer; }
        int getCurrentReg(bool increase = false) { return (increase) ? current_reg++ : current_reg; }
        void increaseCurrentReg() { current_reg++; }
        int getCurrentLabel(bool increase = false) { return (increase) ? current_label++ : current_label; }
        void increaseCurrentLabel() { current_label++; }

        string freshVar();
        string globalFreshVar();
        ExpNode* arithmaticCalc(ExpNode& exp1, ExpNode& exp2, TypesEnum type, const string binop);
        ExpNode* booleanCalc(ExpNode& exp1, ExpNode& exp2, TypesEnum type, const string relop);
        ExpNode* processNot(ExpNode& exp);
        ExpNode* processAnd(ExpNode& exp1, ExpNode& exp2);
        ExpNode* processOr(ExpNode& exp1, ExpNode& exp2);
        ExpNode *processTrueOrFalse(const bool isTrue);
};


#endif