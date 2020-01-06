#include "Interpreter.h"

class Value: public Expression {
private:
    const double val;
public:
    Value(double val) : val(val){}
    double calculate() override;
    virtual ~Value();
};

class Variable: public Expression {
private:
    std::string name;
    double value;
public:
    Variable(std::string name, double value);
    double calculate() override;
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double num);
    Variable& operator-=(double num);
    Variable& operator++(int num);
    Variable& operator--(int num);
    virtual ~Variable() {};

};

class UnaryOperator: public Expression {
protected:
    Expression* ex;
public:
    UnaryOperator(Expression* e): ex(e){}
    virtual ~UnaryOperator();
};


class UPlus: public UnaryOperator {
public:
    UPlus(Expression* ex);
    double calculate() override;
    virtual ~UPlus() {};
};

class UMinus: public UnaryOperator {
public:
    UMinus(Expression* ex);
    double calculate() override;
    virtual ~UMinus() {};
};

class BinaryOperator: public Expression {
protected:
    Expression* right;
    Expression* left;

public:
    BinaryOperator(Expression* lft, Expression* rght): left(lft), right(rght) {};
    virtual ~BinaryOperator();
};

class Plus: public BinaryOperator {
public:
    Plus(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Plus() {};
};

class Minus: public BinaryOperator {
public:
    Minus(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Minus() {};
};

class Mul: public BinaryOperator {
public:
    Mul(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Mul() {};
};

class Div: public BinaryOperator {
public:
    Div(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Div() {};
};