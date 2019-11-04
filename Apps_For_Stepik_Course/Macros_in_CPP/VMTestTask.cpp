#include <iostream>
using namespace std;

struct Expression // base type
{
    virtual double evaluate() const = 0;
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

// simple way of check if 'left' & 'right' are made of the same class that is derived from base class:
bool check_equals(Expression const *left, Expression const *right)
{
    return *reinterpret_cast<const void *const *>(left) == *reinterpret_cast<const void *const *>(right);
    /*
    // some other ways of how to do the same:

    int* a = *((int**)left);
	int* b = *((int**)right);
	return a==b;

    return (left->_vptr == right->_vptr);

    return (left->_vptr[0] == right->_vptr[0]) ? true : false;

    return (*((size_t*)left) == *((size_t*)right));

    return *(int*) left == *(int*) right;

    return (*(int**)left) == (*(int**)right);

    return *(void **)left == *(void **)right;

    return *(char *) left == *(char *) right;

    return *(size_t*)left == *(size_t*)right;

    return ((size_t**)&left)[0][0] == ((size_t**)&right)[0][0];

    // this is possible even with MACROs:
    #define check_equals(left, right) (*(size_t *)(left) == *(size_t *)(right))

    return ((void(*(*(&)[2]))(const Expression&))left)[0][0] == ((void(*(*(&)[2]))(const Expression&))right)[0][0];
    */
    /*
    1. Целочисленный тип

    Указатель на класс Expression указывает на первое поле этого класса. То есть он хранит
    адрес этого поля. А первое поле - это, скорее всего, указатель на таблицу виртуальных функций.

    Указатель на первое поле класса Expresiion после (int const *)
    стал указателем на константное целочисленное значение, причём хранимый им адрес не изменился.

    Узнавая это значение(разыменовывая указатель на Expresion),
    мы по сути попадаем в ячейку, в которой хранится значение указателя на виртуальную таблицу,
    которое является целочисленным типом, так как адреса - это целые числа, а указатели хранят адреса.

    То есть, по сути, мы узнаём адрес таблицы, которая для одинаковых классов одинакова и имеет один и тот же адрес.
    2. Указатель на указатель

    Так как(с большой вероятностью) первое поле у объекта класса Expression и его наследников- это указатель на таблицу виртуальных функций, то, так как указатель на объект класса Expression указывает на его первое поле, можно предположить, что он указывает на указатель,
    который будет хранить одинаковые адреса таблиц виртуальных функций для одинаковых классов.
    Поэтому сравнив эти адреса, мы сравним указатели на таблицы виртуальных функций. Можно было сделать и так.

    bool check_equals(Expression const *left, Expression const *right){
        if ((*((int const *)(left))) == (*((int const *)(right)))){
            return true;
        }else{
            return false;
        }
    }
    */
    /*
    Походу у меня самое идиотское решение. Хотел сделать таким же методом, как и в задании с undefind behavior: ну там, где нужно было private поля прочесть.
    Зная о том, что указатель на таблицу виртуальных методов находится в самом начале, я решил прочесть это значение, а потом сравнивать его с аналогичным значением другого объекта.
    Вот только оператор new (<указатель>) <тип>[<размер>] требует, чтобы указатель не ссылался на константный тип (у нас тут Expression const *). Так что прогуглил, что есть const_cast, вроде по заданию не запрещено пользоваться. Ну а дальше создаю по массиву из одного элемента прямо в начале каждого объекта по их указателю, считываю значения и сравниваю.

    #include <cstddef>
    #include <new>

    bool check_equals(Expression const *left, Expression const *right)
    {
        Expression *pl = const_cast<Expression*>(left);
        Expression *pr = const_cast<Expression*>(right);
        size_t *ml = new (pl) size_t[1];
        size_t *mr = new (pr) size_t[1];
        return (ml[0] == mr[0]);
    }
*/
}