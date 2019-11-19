#include <iostream>
using namespace std;

struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr {
    ~ScopedPtr() {
        counter--;
        cout << "destructor : counter is: " << counter << endl;
        if (counter <= 0) {
            delete ptr_;
            ptr_ = 0;
            cout << "destructor : nulled ptr_";
        }
    }
    Expression *get() const {
        return ptr_;
    }
    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        // delete ptr_;
        ptr_ = 0;
        return tmp;
    }
    void reset(Expression *ptr = 0) {
        delete ptr_;
        ptr_ = ptr;
    }
    Expression &operator*() const {
        return *ptr_;
    }
    Expression *operator->() const {
        return ptr_;
    }

   private:
    ScopedPtr(const ScopedPtr &);
    ScopedPtr &operator=(const ScopedPtr &);

    Expression *ptr_;
    int counter = 0;
};

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
        cout << "destructor : ptrCounter no is : " << ptrCounter << endl;
        if (ptrCounter <= 0) {
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
    SharedPtr &operator=(const SharedPtr &) {
        (this->refCounter)--;
    }
    // Expression* get() const
    // void reset(Expression *ptr = 0)
    // Expression& operator*() const
    // Expression* operator->() const

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
оператор присваивания уменьшает счетчик ссылок левого операнда на 1,
если внутри левого SharedPtr хранится ненулевой указатель, увеличивает счетчик правого SharedPtr на 1,
если в правом SharedPtr хранится ненулевой указатель
(обычное дело для оператора присваивания — сначала освобождаем старые ресурсы, потом выделяем новые, но при этом нужно быть особенно внимательным с присваиванием самому себе).
Для класса SharedPtr могут оказаться полезными следующие методы (кроме операторов * и ->, конструктора копирования, оператора присваивания, деструктора и конструктора):

метод get, как и в случае со ScopedPtr,
метод reset — аналогичен reset у ScopedPtr, но освобождает память, только если счетчик ссылок после декремента равен 0.
*/