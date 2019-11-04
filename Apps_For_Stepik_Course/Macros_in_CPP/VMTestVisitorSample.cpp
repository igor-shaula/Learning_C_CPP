#include <iostream>
using namespace std;

struct Expression // base type
{
    virtual double evaluate() const = 0;
    // if we add any virtual method here - we'll have to realize it in all derivatives,
    // but we'll use Visitor pattern - to avoid adding methods in all chain of inheritance.
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value) : value(value) {}

    double evaluate() const { return value; }

private:
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
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

// VISITOR = = =
struct Visitor
{
    virtual void visitNumber(Number const *number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const *bo) = 0;
    ~Visitor() {}
};

int main()
{
    // this code block has to work: sample of 3 + 4.5 * 5

    Expression *sub = new BinaryOperation(new Number(4.5), '*', new Number(5));
    cout << "first evaluation: " << sub->evaluate() << endl;

    Expression *expr = new BinaryOperation(new Number(3), '+', sub);
    std::cout << expr->evaluate() << std::endl;

    delete expr; // sub будет правым операндом expr, поэтому его удалять не нужно

    return 0;
}