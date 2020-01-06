#include "Interpreter.h"

/**
* this class represent a number.
**/
class Value: public Expression {
private:
    const double val;
public:
    Value(double val) : val(val){}
    double calculate() override;
    virtual ~Value();
};

/**
* this class represent a Variable that has an assigned value.
**/
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

/**
* this is an abstract class that represent an unary operator
* that holds one expression.
**/
class UnaryOperator: public Expression {
protected:
    Expression* ex;
public:
    UnaryOperator(Expression* e): ex(e){}
    virtual ~UnaryOperator();
};

/**
* this class represent an unary plus expression,
* aka an expression with a plus before him.
**/
class UPlus: public UnaryOperator {
public:
    UPlus(Expression* ex);
    double calculate() override;
    virtual ~UPlus() {};
};

/**
* this class represent an unary minus expression.
* aka an expression with a minus before him.
**/
class UMinus: public UnaryOperator {
public:
    UMinus(Expression* ex);
    double calculate() override;
    virtual ~UMinus() {};
};

/**
* this is an abstract class that represent a binary operator
* that holds tow expressions.
**/
class BinaryOperator: public Expression {
protected:
    Expression* right;
    Expression* left;

public:
    BinaryOperator(Expression* lft, Expression* rght): left(lft), right(rght) {};
    virtual ~BinaryOperator();
};

/**
* this class represent a binary plus on tow expressions,
* and knows to calculate the sum of them. 
**/
class Plus: public BinaryOperator {
public:
    Plus(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Plus() {};
};

/**
* this class represent a binary minus on tow expressions,
* and knows to calculate the substraction of them. 
**/
class Minus: public BinaryOperator {
public:
    Minus(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Minus() {};
};


/**
* this class represent a multiply of tow expressions,
* and knows to calculate the multiplication of them. 
**/
class Mul: public BinaryOperator {
public:
    Mul(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Mul() {};
};

/**
* this class represent a division of tow expressions,
* and knows to calculate the division of them. 
**/
class Div: public BinaryOperator {
public:
    Div(Expression* left, Expression* right): BinaryOperator(left, right) {}
    ;
    double calculate() override;
    virtual ~Div() {};
};
