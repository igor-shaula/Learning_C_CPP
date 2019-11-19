#include <iostream>
using namespace std;

struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr {
    explicit SharedPtr(Expression *ptr = 0) {
        cout << "constructor : given ptr: " << ptr << endl;
        if (ptr != 0) {
            ptr_ = ptr;
            ptrCounter++;
            refCounter = 1;
            cout << "constructor : ptrCounter is : " << ptrCounter << endl;
        }
    }
    ~SharedPtr() {
        ptrCounter--;
        cout << "destructor : ptrCounter now is : " << ptrCounter << endl;
        if (ptrCounter == 0) {
            delete ptr_;
            ptr_ = 0;
            cout << "destructor : nulled ptr_" << endl;
        }
        if (ptr_ != 0) {
            refCounter--;
            cout << "destructor : refCounter now is : " << refCounter << endl;
        }
    }
    SharedPtr(const SharedPtr &other) {
        if (other.ptr_ != 0)
            refCounter++;  // this has to be the only place of this counter incrementation
    }
    SharedPtr &operator=(const SharedPtr &other) {
        if (this->ptr_ != 0)
            (this->refCounter)--;
        else {
        }
        // if (other.ptr_ != 0)
        // (other.refCounter)++;
        // todo - continue here
    }
    Expression *get() const {
        return ptr_;
    }
    void reset(Expression *ptr = 0) {
        delete ptr_;
        ptr_ = ptr;
        // if(ptr_ != 0)
        // investigate all cases that might occur here
    }
    /* method release() is absent in the task */
    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        ptr_ = 0;
        return tmp;
    }
    Expression &operator*() const {
        return *ptr_;
    }
    Expression *operator->() const {
        return ptr_;
    }

   private:
    Expression *ptr_;
    int ptrCounter = 0;
    int refCounter = 0;  // depends only on quantity of different pointers - in fact how many real instances we really have
};

/*
Для ScopedPtr мы запретили копирование, однако, копирование можно и разрешить.
Это позволит реализовать более продвинутый умный указатель — SharedPtr.
Он отличается от ScopedPtr тем, что кроме хранения указателя на объект, он хранит еще и счетчик ссылок (количество объектов SharedPtr, которые хранят один и тот же указатель).

Имея такой счетчик, мы можем определить момент, когда на объект, выделенный в куче, не останется больше ссылок (когда счетчик ссылок станет равным 0), и освободить память.

Поддержка счетчика ссылок состоит из нескольких частей:

в конструкторе SharedPtr от ненулевого указателя мы инициализируем счетчик ссылок в 1
(конструктор создает первый SharedPtr, который хранит указатель),
в конструкторе копирования мы увеличиваем счетчик ссылок на 1, если копируемый SharedPtr содержит ненулевой указатель
(конструктор копирования создает еще один SharedPtr с указателем на тот же самый объект),
в деструкторе мы уменьшаем значение счетчика на 1, если в объекте SharedPtr хранится ненулевой указатель
(мы удаляем один SharedPtr, который указывает на объект в куче),
оператор присваивания:
уменьшает счетчик ссылок левого операнда на 1, если внутри левого SharedPtr хранится ненулевой указатель,
увеличивает счетчик правого SharedPtr на 1, если в правом SharedPtr хранится ненулевой указатель
(обычное дело для оператора присваивания — сначала освобождаем старые ресурсы, потом выделяем новые, но при этом нужно быть особенно внимательным с присваиванием самому себе).
Для класса SharedPtr могут оказаться полезными следующие методы (кроме операторов * и ->, конструктора копирования, оператора присваивания, деструктора и конструктора):
метод get, как и в случае со ScopedPtr,
метод reset — аналогичен reset у ScopedPtr, но освобождает память, только если счетчик ссылок после декремента равен 0.
*/

struct Number;
struct BinaryOperation;

// VISITOR = = =
struct Visitor {
    virtual void visitNumber(Number const *number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const *bop) = 0;
    ~Visitor() {}
};

struct Expression  // base type
{
    virtual double evaluate() const = 0;
    // if we add any virtual method here - we'll have to realize it in all derivatives,
    // but we'll use Visitor pattern - to avoid adding methods in all chain of inheritance.
    virtual ~Expression() {}
    // visit() allows us to add only one method instead of many in Expression, Number & BinaryOperation.
    virtual void visit(Visitor *visitor) const = 0;
};

struct Number : Expression {
    Number(double value) : value(value) { cout << "Number " << value << " created" << endl; }

    double evaluate() const { return value; }

    void visit(Visitor *visitor) const { visitor->visitNumber(this); }

    double getValue() const { return value; }

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

    void visit(Visitor *visitor) const { visitor->visitBinaryOperation(this); }

    Expression const *getLeft() const { return left; }
    Expression const *getRight() const { return right; }
    char getOp() const { return op; }

   private:
    Expression const *left;
    Expression const *right;
    char op;
};

struct PrintBinaryOperationsVisitor : Visitor {
    void visitNumber(Number const *number) { cout << number->getValue() << ' '; }

    void visitBinaryOperation(BinaryOperation const *bop) {
        bop->getLeft()->visit(this);
        cout << bop->getOp() << ' ';
        bop->getRight()->visit(this);
        cout << "-> " << bop->evaluate() << endl;
    }
};

struct PrintVisitor : Visitor {
    void visitNumber(Number const *number) {
        std::cout << number->getValue();
    }

    void visitBinaryOperation(BinaryOperation const *bop) {
        std::cout << '(';
        bop->getLeft()->visit(this);
        std::cout << bop->getOp();
        bop->getRight()->visit(this);
        std::cout << ')';
    }
};

void runAllTests() {
    // Number n1(1.5);
    // Number n2 = n1;
    // SharedPtr sp1(&n1);
    // SharedPtr sp2(&n2);
    // SharedPtr spe1 = sp1;
    // SharedPtr spe2 = sp2;

    SharedPtr p1;
    {
        SharedPtr p2(new Number(1.1));
        // SharedPtr p2(new Expression("expr1"));
        SharedPtr p3(new Number(1.2));
        // SharedPtr p3(new Expression("expr2"));
        SharedPtr p4(p2);
        SharedPtr p5;
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(NULL);
        p3 = p5;
        p5.reset(NULL);
        SharedPtr p6;
        SharedPtr p7;
        p7 = p7;
        p7.reset(NULL);
        p7.reset(new Number(1.3));
        // p7.reset(new Expression("expr3"));
        SharedPtr p8(new Number(1.4));
        // SharedPtr p8(new Expression("expr4"));
        p8.reset(NULL);
    }
    p1 = p1;
}
int main() {
    runAllTests();
    return 0;
}