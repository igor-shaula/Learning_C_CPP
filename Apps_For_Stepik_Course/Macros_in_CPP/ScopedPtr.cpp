#include <iostream>
using namespace std;

struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr {
    explicit ScopedPtr(Expression *ptr = 0) {
        cout << "constructor : counter was: " << counter << endl;
        if (ptr != 0) {
            ptr_ = ptr;
            counter++;
            cout << "constructor : counter is: " << counter << endl;
        }
    }
    ~ScopedPtr() {
        counter--;
        cout << "destructor : counter is: " << counter << endl;
        if (counter <= 0) {
            delete ptr_;
            ptr_ = 0;
            cout << "destructor : nulled ptr_" << endl;
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

void testScopedPtrUse() {
    // todo...
}
/*
На предыдущих неделях вы уже набили достаточно шишек на ручном управлении памятью.
Пришло время задуматься о более разумном подходе.
Начнем с довольно простого случая — рассмотрим динамические объекты, время жизни которых ограничено блоком ({} — ограничивают блок в C++).
Указатель на такой динамический объект внутри блока можно "связать" со временем жизни объекта на стеке:
достаточно сохранить этот указатель в некотором объекте на стеке, а в деструкторе этого объекта вызвать delete.
Так как деструктор объекта, созданного на стеке, вызывается автоматически при выходе из блока, то delete тоже будет вызван автоматически.

Такой класс-обертку мы будем называть ScopedPtr.
Стоит заметить, что копирование такого объекта может приводить к серьезным проблемам,
например, к повторному освобождению памяти (два объекта хранят внутри один и тот же указатель и вызов delete будет сделан дважды).
Поэтому нужно запретить вызов конструктора копирования и оператора присваивания таких объектов.
Добиться этого можно объявив их в private секции класса.
При этом даже не нужно их реализовывать — снаружи класса никто не сможет их вызвать, а внутри класса мы этого делать не будем.

Какой интерфейс может быть у такого класса ScopedPtr? Кроме уже известных вам операторов * и ->, деструктора и конструктора, полезными могут оказаться следующие методы:

get — возвращает указатель, сохраненный внутри ScopedPtr (например, чтобы передать его в какую-то функцию);
release — забирает указатель у ScopedPtr и возвращает значение этого указателя, после вызова release ScopedPtr не должен освобождать память (например, чтобы вернуть этот указатель из функции);
reset — метод заставляет ScopedPtr освободить старый указатель, а вместо него захватить новый (например, чтобы переиспользовать ScopedPtr, так как оператор присваивания запрещен).
*/

int main() {
    testScopedPtrUse();
    return 0;
}