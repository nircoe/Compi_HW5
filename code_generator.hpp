#ifndef CODE_GENERATOR_HPP
#define CODE_GENERATOR_HPP

#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include "bp.hpp"
#include "types.hpp"
#include <algorithm>

using std::string;
using std::stack;
using std::queue;

class CodeGenerator {
    CodeBuffer* buffer;
    int current_reg;
    int current_label;
    string func_vars_arr;

    public:

        CodeGenerator(CodeBuffer* _buffer) : buffer(_buffer), current_reg(0) {};
        
        CodeBuffer* getCodeBuffer() { return buffer; }
        int getCurrentReg(bool increase = false) { return (increase) ? current_reg++ : current_reg; }
        void increaseCurrentReg() { current_reg++; }
        int getCurrentLabel(bool increase = false) { return (increase) ? current_label++ : current_label; }
        void increaseCurrentLabel() { current_label++; }

        void emitPrint();
        string freshVar();
        string globalFreshVar();
        void allocaVarsForFunc();
        void storeVar(ExpNode* exp, StatementNode* sn, int offset);
        void initVar(IdNode* id, StatementNode* sn, TypesEnum type, int offset);
        void loadVar(ExpNode* exp, int offset);
        string processNumAssign(ExpNode& exp, string var, string value);
        void startFunc(FuncDeclNode* func, int func_counter);
        void endFunc(RetTypeNode* type, StatementsNode* s, MarkerNode* marker);
        void processFirstStatement(StatementsNode* statements, StatementNode* statement);
        void processStatements(StatementsNode* statements, StatementNode* new_statement);
        void processEndStatement(StatementNode* statement, StatementsNode* statements);
        void processBoolExp(ExpNode* exp);
        void processStatementCall(StatementNode* statement, CallNode* call);
        void processCall(CallNode* call, vector<ExpNode*> exprs = {});
        void processReturn(StatementNode* statement);
        void processReturn(StatementNode* statement, ExpNode* exp);
        void processIfElse(StatementNode* new_statement, ExpNode* exp, StatementNode* if_statement, StatementNode* else_statement = nullptr);
        void processWhile(StatementNode* new_statement, ExpNode* exp, StatementNode* statement);
        void processNot(ExpNode* new_exp, ExpNode* exp);
        void processAnd(ExpNode* new_exp, ExpNode* exp1, ExpNode* exp2);
        void processOr(ExpNode* new_exp, ExpNode* exp1, ExpNode* exp2);
        void processTrueOrFalse(ExpNode* new_exp, const bool isTrue = false);
        void processBreakContinue(StatementNode* statement, bool isBreak = false);
        void processParentheses(ExpNode* new_exp, ExpNode* exp);
        void processBinop(ExpNode* new_exp, ExpNode* exp1, ExpNode* exp2, const char binop);
        void processRelop(ExpNode* new_exp, ExpNode* exp1, ExpNode* exp2, const string relop);
        void processExpCall(ExpNode* exp, CallNode* call);
        void processExpNum(ExpNode* exp, NumNode* num);
        void processExpString(ExpNode* exp, StringNode* string_node);
        void processConvertion(ExpNode* new_exp, ExpNode* exp);
};


#endif