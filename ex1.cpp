#include <iostream>
#include "ex1.h"
#include <string>
#include "Expression.h"

using namespace std;


Value :: ~Value()
{

}

double Value:: calculate()

{
	return val;
}

//Variable

Variable :: Variable(string n, double d)
{
	name = n;
	value = d;
}

double Variable :: calculate()
{
	return value;
}

Variable& Variable :: operator++()
{
	value += 1;
	return *this;
}

Variable& Variable :: operator--()
{
	value -= 1;
	return *this;
}

Variable& Variable :: operator+=(double num)
{
	value += num;
	return *this;
}

Variable& Variable :: operator-=(double num)
{
	value -= num;
	return *this;
}

Variable& Variable :: operator++(int num)
{
	value += 1;
	return *this;
}

Variable& Variable :: operator--(int num)
{
	value -= 1;
	return *this;
}

//UnaryOperator


UnaryOperator :: ~UnaryOperator()
{
	delete ex;
}

//UPlus

UPlus :: UPlus(Expression* ex): UnaryOperator(ex) {}

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