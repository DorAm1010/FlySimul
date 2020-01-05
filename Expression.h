
#ifndef FLYSIMUL_EXPRESSION_H
#define FLYSIMUL_EXPRESSION_H

/**
 * Expression Interface
 */
class Expression {

public:
    virtual double calculate() = 0;
    virtual ~Expression() {}
};

#endif //PROJECT_EXPRESSION_H
