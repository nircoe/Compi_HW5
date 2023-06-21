#ifndef COMPI_TYPES_H
#define COMPI_TYPES_H

#include <vector>
#include <iostream>
#include <string>
#include "bp.hpp"
#define YYSTYPE Node*

using std::vector;
using std::string;
using std::pair;

typedef vector<pair<int,BranchLabelIndex>> List;

enum TypesEnum {
    TYPE_VOID,
    TYPE_BYTE,
    TYPE_BOOL,
    TYPE_INT,
    TYPE_STRING,
    NULL_TYPE
};

/**
 * everyone inherits it
 */
class Node {
public:
    virtual ~Node() {};
};

/**
 * type of token
 */
class TypeNode : public Node {
public:
    TypesEnum type;

    TypeNode(TypesEnum _type) : type(_type) {};
};

/**
 * override token type
 */
class OverrideNode : public Node {
public:
    bool isOverride;

    OverrideNode(bool _isOverride = false) : isOverride(_isOverride) {};
};

/**
 * id token type
 */
class IdNode : public Node {
public:
    const string name;
    string var;
    TypesEnum type;

    IdNode(const string _name) : name(_name), var(""), type(NULL_TYPE) {};
};

/**
 * num token type
 */
class NumNode : public Node {
public:
    string num_val;
    TypesEnum type;

    NumNode(string _num_val, TypesEnum _type = TYPE_INT) : num_val(_num_val), type(_type) {};
};

/**
 * return type of func
 */
class RetTypeNode : public Node {
public:
    TypesEnum type;

    RetTypeNode(TypesEnum _type) : type(_type) {};
};

/**
 * expression token
 */
class ExpNode : public Node {
public:
    TypesEnum type;
    string var;
    List true_list;
    List false_list;
    List next_list;
    string start_label;
    string value;

    ExpNode(TypesEnum _type, string _var) : type(_type), var(_var) {};
    ExpNode(TypesEnum _type) : type(_type) {};
    bool isBoolExp() { return type == TYPE_BOOL; }
};

/**
 * expression list token
 */
class ExpListNode : public Node {
public:
    vector<ExpNode*> exprs;

    ExpListNode(const vector<ExpNode*>& _exprs) : exprs(_exprs) {};
};

/**
 * formal declarations token
 */
class FormalDeclNode : public Node {
public:
    TypesEnum type;
    const string name;
    string var;

    FormalDeclNode(TypesEnum _type, const string& _name, string _var) : type(_type), name(_name), var(_var) {};
};

/**
 * function declarations token
 */
class FuncDeclNode : public Node{
public:
    TypesEnum type;
    string func_name;
    vector<FormalDeclNode*> declarations;
    List next_list;

    FuncDeclNode(TypesEnum _type , string _func_name, const vector<FormalDeclNode*>& _declarations) :
                    type(_type), func_name(_func_name), declarations(_declarations) {};
};

/**
 * formal token type
 */
class FormalsNode : public Node {
public:
    vector<FormalDeclNode*> declarations;

    FormalsNode(const vector<FormalDeclNode*>& _declarations) : declarations(_declarations) {};
    FormalsNode() {};
};

/**
 * call token
 */
class CallNode : public Node {
public:
    TypesEnum type;
    const string call_name;
    string var;
    string start_label;
    List true_list;
    List false_list;
    List next_list;

    CallNode(TypesEnum _type, const string _name) : type(_type), call_name(_name) {};
};

/**
 * formal list token type
 */
class FormalsListNode : public Node {
public:
    vector<FormalDeclNode*> declarations;

    FormalsListNode(const vector<FormalDeclNode*>& declarations) : declarations(declarations) {};
};

class StatementNode : public Node {
public:
    List next_list;
    List break_list;
    List continue_list;
    string start_label;
    bool isBP;
    bool isBreak;

    StatementNode() : isBP(false), isBreak(false) {};
};

class StatementsNode : public Node {
public:
    List next_list;
    List break_list;
    List continue_list;
    vector<StatementNode*> statements;
    string start_label;

    StatementsNode(const vector<StatementNode*>& _statements, string _start_label = "") : 
                    statements(_statements), start_label(_start_label) {};
};

class MarkerNode : public Node {
public:
    string label;
    List next_list;
    MarkerNode(List _next_list) : next_list(_next_list) {};
};


bool ConversionLegality(TypesEnum from, TypesEnum to);
bool AssignLegality(TypesEnum leftType, TypesEnum rightType);
TypesEnum SumType(TypesEnum left, TypesEnum right);
TypesEnum StringToType(const string& s);
string TypeToString(TypesEnum type);
bool IsBoolExp(ExpNode& exp1, ExpNode& exp2);
bool IsTypeExp(TypeNode& type, ExpNode& exp);


#endif //COMPI_TYPES_DECLARATION_H
