#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <regex>
#include <vector>


//#include "Expression.h"
//#include "Interpreter.h"
#include "ex1.h"
using namespace std;

/**
 * constructor.
 **/
Interpreter::Interpreter() {
    variableVec = new vector<string>();
    valuesVec = new vector<double>();
}

/**
 * interpret a string that represent an expression, to expression.
 * @param exString string representation of expression.
 * @return expression.
 **/
Expression* Interpreter::interpret(string exString) {

	stack <string> operatorStack;
	queue <string> outputQueue;

	int ind;
	string reg = "(a-zA-Z)+_?(a-zA-Z0-9)";
    regex variableReg(reg);  //[a-zA-Z]+_?[a-zA-Z0-9]*/g");
//	regex numberReg("-?0|([1-9])"); //[0-9]*)(\\.[0-9]+)?");


	for(ind = 0; ind < exString.length(); ind++) {

		//number
		if(isdigit(exString[ind])) {

			int endInd = ind;

			//checks where the number ends.
			while(endInd < exString.length() && (isdigit(exString[endInd]) || exString[endInd] == '.')) {
				endInd++;
			}

			string hopefullyNumber = exString.substr(ind, endInd - ind).c_str();

			//check if is valid number
			//if(regex_search(hopefullyNumber, numberReg)) {
				outputQueue.push(hopefullyNumber);
			//} else {
			//	try {
			//		throw ( "invalid number");
			//	} catch(const char* e) {
			//		cout<< e << endl;
			//	}
			//}

			ind = endInd - 1;

		}

		else if(exString[ind] == '(') {
			operatorStack.push("(");
		}

		else {

			int pre = operatorPre(string(1,exString[ind]));

			if(pre > 0) {

				try {
					if(ind == exString.length()) {
						throw("operator at the end of expression is not valid");
					}
				} catch (const char* e) {
					throw e;
				}

				try {
					if(operatorPre(string(1,exString[ind + 1])) == 1) {
						throw("tow operators in a row is not valid");
					}
				} catch (const char* e) {
                    throw e;
				}

				if(pre == 1) {

                    if (!operatorStack.empty()) {
                        int preTop = operatorPre(operatorStack.top());
                        while (preTop == 3 && !operatorStack.empty()) {
                            outputQueue.push(operatorStack.top());
                            operatorStack.pop();
                            preTop = operatorPre(operatorStack.top());
                        }
                    }

                    operatorStack.push(string(1,exString[ind]));
				}

				if(pre == 2) {

					if(ind == 0 || exString[ind  - 1] == '(' || exString[ind  - 1] == '/' || exString[ind  - 1] == '*') {//isdigit(exString[ind - 1])) {
						if(exString[ind] == '+') {
							operatorStack.push("^");
						} else {
							operatorStack.push("~");
						}

					} else {

                        //pop pre 1 from top of stack and push to queue,
                        // and push the operator into stack
                        if (!operatorStack.empty()) {
                            int preTop = operatorPre(operatorStack.top());
                            while ((preTop == 1 || preTop == 3) && !operatorStack.empty()) {
                                outputQueue.push(operatorStack.top());
                                operatorStack.pop();
                                preTop = operatorPre(operatorStack.top());
                            }
                        }

                        if(exString[ind] == '+') {
                            operatorStack.push("+");
                        } else {
                            operatorStack.push("-");
                        }
					}
				}
			}
		}

		if(exString[ind] == ')') {

			//move operators from stack to queue, until theres an '('.
			// then throw the '('
			while(operatorStack.top() != "(") {
				outputQueue.push(operatorStack.top());
				operatorStack.pop();
			}

			try {
				if(!operatorStack.empty()) {
					operatorStack.pop();
				} else {
					throw("brackets in expression are not valid");
				}
			} catch (const char* e){
                throw e;
			}
		} else {

			if(isalpha(exString[ind])) {

				int endInd = ind;

				//checks where the number ends.
				while(endInd < exString.length() && (isalpha(exString[endInd]) || isdigit(exString[endInd]) || exString[endInd] == '_')) {
					endInd++;
				}

				string hopefullyVariable = exString.substr(ind, endInd - ind);
				outputQueue.push(hopefullyVariable);
				//check if is valid variable
				//if(regex_match(hopefullyNumber, numberReg)) {
					
				//} else {
				//	throw (hopefullyNumber + "is not a valid number");
				//}

				ind = endInd - 1;
			}
		}
	}

	// empty stack into the queue
	while(!operatorStack.empty()) {
		outputQueue.push(operatorStack.top());
			operatorStack.pop();
	}

	return produceExpression(outputQueue);
}

/**
 * checks an operator/character precedence.
 * @param c operator/character.
 * @return c's precedence.
 */
 int Interpreter::operatorPre(string c) {

 	if(c == "+" || c == "-") {
 		return 2;
 	}

 	if(c == "*" || c == "/") {
 		return 1;
 	}

 	if(c == "^" || c == "~") {
 		return 3;
 	}

 	return 0;
 }

 /**
  * produce an expression from a postfix queue.
  * @param q postfix queue.
  * @return expression.
  */
 Expression* Interpreter::produceExpression(queue <string> q) {
 	stack <Expression*> s;
 	int pre;
 	Expression* finalEx;
 	Expression* ex1;
     Expression* ex2;
 	string top;
 	string topOp;
 	vector<string>::iterator itr;

     pre = operatorPre(q.front());

     bool first = true;

 	while(!q.empty()) {

        top = q.front();
        pre = operatorPre(q.front());

        if (pre == 0) {



            if (isdigit(top[0])) {
                finalEx = new Value(stod(top));
            } else {
                itr = find(variableVec->begin(), variableVec->end(), top);
                finalEx = new Variable(top, valuesVec->at(distance(variableVec->begin(), itr)));
            }

            s.push(finalEx);
            q.pop();

        } else {

            ex1 = s.top();
            s.pop();

            topOp = q.front();
            q.pop();

            if (operatorPre(topOp) != 3) {
                ex2 = s.top();
                s.pop();
            }

            switch (topOp[0]) {
                case '^':
                    finalEx = new UPlus(ex1);
                    break;
                case '~':
                    finalEx = new UMinus(ex1);
                    break;
                case '+':
                    finalEx = new Plus(ex2, ex1);
                    break;
                case '-':
                    finalEx = new Minus(ex2, ex1);;
                    break;
                case '*':
                    finalEx = new Mul(ex2, ex1);
                    break;
                case '/':
                    finalEx = new Div(ex2, ex1);
            }

                    s.push(finalEx);


            first = false;
        }
    }

 	return finalEx;

 }

 /**
  * set variables and their values, for future evaluations.
  * @param s variables to set, in form - "var1=value1;var2=value2...".
  */
 void Interpreter::setVariables(string s) {
 	int end = 0;
 	int mid = 0;
 	string value = "";
    bool done = false;
    vector<string>:: iterator it;
     double doubleVal;

 	while(!done && s != "") {
 		mid = s.find("=");
 		end = s.find(";");
 		if(end == -1) {
 		    end = s.length();
 		    done = true;
 		}
 		string key = s.substr(0,mid);
 		value = s.substr(mid + 1, end - mid - 1);
 		if(!done) {
            s = s.substr(end + 1, s.length() - end - 1);
        }

 		try {
            doubleVal = stod(value);
        } catch(invalid_argument e) {
 		    throw ("variables is not defined well");
 		}
 		it = find(variableVec->begin(), variableVec->end(), key);
 		int d = distance(variableVec->begin(), it);
 		int size = variableVec->size() ;
        if(d == size) {

           variableVec->push_back(key);
           valuesVec->push_back(doubleVal);
         } else {

            variableVec->insert(variableVec->begin(), key);
            valuesVec->insert(valuesVec->begin(), doubleVal);
        }
 		}
 }


 /**
  * destructor.
  */
 Interpreter::~Interpreter() {
     if(variableVec != NULL) {
       delete variableVec;
    }
     if(valuesVec != NULL) {
         delete valuesVec;
     }
 }