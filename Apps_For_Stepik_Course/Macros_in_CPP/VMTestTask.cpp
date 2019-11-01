#include <iostream>
using namespace std;

struct Expression // base type
{
    virtual double evaluate() const = 0;
    virtual double getValue() const = 0;
    virtual double getLeft() const = 0;
    virtual double getRight() const = 0;
};

struct Number : Expression
{
    Number(double value) : value(value) {}

    double evaluate() const {};

    double getValue() const { return value; }

private:
    virtual double getLeft() const {};
    virtual double getRight() const {};
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right) {}

    double evaluate() const
    {
        switch (op)
        {
        case '+':
            return left->getValue() + right->getValue();
        case '-':
            return left->getValue() - right->getValue();
        case '*':
            return left->getValue() * right->getValue();
        case '/':
            return left->getValue() / right->getValue();
        default:
            break;
        }
    };

    double getLeft() const { return left->getValue(); }
    double getRight() const { return right->getValue(); }

private:
    double getValue() const {};
    Expression const *left;
    Expression const *right;
    char op;
};

int main()
{
    // this code block has to work: sample of 3 + 4.5 * 5
    // 1 - сначала создаём объекты для подвыражения 4.5 * 5
    Expression *sub = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    cout << "first evaluation: " << sub->evaluate() << endl;
    Expression *expr = new BinaryOperation(new Number(3), '+', sub);
    cout << "left: " << expr->getLeft() << endl;
    cout << "right: " << expr->getRight() << endl;

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sub будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;

    return 0;
}