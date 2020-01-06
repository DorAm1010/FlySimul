#include "ex1.h"

using namespace std;


/**
* empty destructor.
**/
Value :: ~Value()
{

}

/**
* calculating the value of a value expression, meaning just returning his value.
**/
double Value:: calculate()

{
    return val;
}

//Variable

/**
* constructor for variable.
* @param n name of variable (the string that reoresent him).
* @param d the value assigned to the variable.
**/
Variable :: Variable(string n, double d)
{
    name = n;
    value = d;
}

/**
* calculates the value of a variable expression,
* meaning returning his value.
**/
double Variable :: calculate()
{
    return value;
}

/**
* operator ++ overloading.
* @return pointer to this after ++.
**/
Variable& Variable :: operator++()
{
    value += 1;
    return *this;
}

/**
* operator -- overloading.
* @return pointer to this after --.
**/
Variable& Variable :: operator--()
{
    value -= 1;
    return *this;
}

/**
* operator += overloading.
* @return pointer to this after +=.
**/
Variable& Variable :: operator+=(double num)
{
    value += num;
    return *this;
}

/**
* operator -= overloading.
* @return pointer to this after -=.
**/
Variable& Variable :: operator-=(double num)
{
    value -= num;
    return *this;
}

/**
* operator ++num overloading.
* @return pointer to this after ++num.
**/
Variable& Variable :: operator++(int num)
{
    value += 1;
    return *this;
}

/**
* operator -- overloading.
* @return pointer to this after --.
**/
Variable& Variable :: operator--(int num)
{
    value -= 1;
    return *this;
}

//UnaryOperator


/**
* delete the only expression.
**/
UnaryOperator :: ~UnaryOperator()
{
    delete ex;
}

//UPlus

/**
* constructor. gets one expression for unary plus.
* @param ex expression for unary plus.
**/
UPlus :: UPlus(Expression* ex): UnaryOperator(ex) {}

/**
* calculates the result of the unary plus.
* @return 
**/
double UPlus :: calculate()
{
    return ex->calculate();
}

//UMinus

UMinus :: UMinus(Expression* ex): UnaryOperator(ex) {}

double UMinus :: calculate()
{
    return - ex->calculate();
}

//BinaryOperator


BinaryOperator :: ~BinaryOperator()
{
    delete left;
    delete right;
}


double Plus :: calculate()
{
    return left->calculate() + right->calculate();
}


double Minus :: calculate()
{
    return left->calculate() - right->calculate();
}

double Mul :: calculate()
{
    return left->calculate() * right->calculate();
}

double Div :: calculate()
{
    double rightCal = right->calculate();

    try {
        if (rightCal == 0) {
            throw ("cant divide by zero!!!");
        }
        return left->calculate() / rightCal;
    } catch(const char* e) {
        throw e;
    }

}
