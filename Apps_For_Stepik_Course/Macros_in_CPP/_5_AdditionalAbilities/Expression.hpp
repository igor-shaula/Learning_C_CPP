#ifndef _LEARNING_C_CPP_EXPRESSION_HPP
#define _LEARNING_C_CPP_EXPRESSION_HPP

#include <iostream>

using namespace std;

struct Expression // base type
{
    virtual double evaluate() const = 0;

    virtual ~Expression() {}
};

struct Number : Expression {
    Number(double value) : value(value) {}

    double evaluate() const { return value; }

private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
            : left(left), op(op), right(right) {}

    double evaluate() const {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            default:
                break;
        }
    };

    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

#endif //_LEARNING_C_CPP_EXPRESSION_HPP