
#ifndef COMPI_SYMBOL_TABLE_H
#define COMPI_SYMBOL_TABLE_H

#include "types.hpp"
#include "hw3_output.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define NA 0

extern int yylineno;
using namespace output;
using std::vector;
using std::string;

class Symbol {
    public:
        const string symbol_name;
        int offset;
        TypesEnum type;
        string var;
        bool function;
        bool isOverride;
        vector<string> args;
        int counter;
        Symbol(const string &_symbol_name, int _offset, TypesEnum _type, string _var, bool _function = false, bool _isOverride = false) : 
                symbol_name(_symbol_name), offset(_offset), type(_type), var(_var), function(_function), isOverride(_isOverride) {};
        ~Symbol() = default;
};

class SymbolTable {
    public:
        SymbolTable* parent;
        vector<Symbol*> symbols;
        bool inWhile;
        SymbolTable(SymbolTable* parent = nullptr) : parent(parent) {
            this->inWhile = (parent) ? parent->inWhile : false;
        };
        ~SymbolTable() {
            for(int i = 0; i < symbols.size(); i++) {
                delete symbols[i];
            }
        };
        bool exists(string symb_name, bool* is_func = nullptr);
};

class TablesStack {
    TablesStack() = default;
public:
    stack<SymbolTable*> table_stack;
    stack<int> offset_stack;
    TypesEnum curr_func_type = NULL_TYPE;

    static TablesStack& getTablesStack() {
        static TablesStack instance;
        return instance;
    }
    // initiated instance
    void Init(); 
    // checks if symbol was declared
    bool symbDeclared(const string& name, bool is_func = false);
    // declares new variable
    void declVar(const string& name, TypesEnum type, string var);
    // declares new function
    int declFunc(const string& name, TypesEnum type, FormalsNode* formals, bool isOverride, int yylineno, int* counter);
    // gets the id type by its name
    TypesEnum getIdType(const string& id_name);
    // gets the id offset by its name
    int getIdOffset(const string& id_name);
    // gets the func-id type by its name and function parameters
    TypesEnum getFuncType(const string &name, vector<ExpNode*>& exprs);
    // checks if the parameters entered to function are valid
    int checkFuncParams(const string& func_name, vector<ExpNode*> exprs, int yylineno);
    // checks if the parameters entered to function are valid
    int checkFuncParams(const string& name, int yylineno);
    // gets the counter of the function by its name
    int getFuncCounter(const string& func_name, vector<ExpNode*> exprs = {});
    // checks if a befitting main function exists
    bool mainExists();
    // check if ID exists in current scope by name
    bool isInCurrScope(const string& name);
    // checks if current scope is within a while statement
    bool isCurrScopeInWhile();
    // opens a global scope
    void openGlobalScope();
    // opens a new scope
    void openScope(bool inWhile = false);
    // closes scope
    void closeScope();
};


#endif //COMPI_SYMBOL_TABLE_H
