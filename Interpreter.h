#include <string>
#include <queue> 
#include <iostream>
#include <map>
#include <vector>
#include "Expression.h"
//#include "ex1.h"

using namespace std;

class Interpreter {

private:
	vector <double>* valuesVec;
    vector <string>* variableVec;
	int operatorPre(string c);
	Expression* produceExpression(queue <string> q);
public :
	Interpreter();
	Expression* interpret(string exString);
	void setVariables(string s);
	virtual ~Interpreter();
};