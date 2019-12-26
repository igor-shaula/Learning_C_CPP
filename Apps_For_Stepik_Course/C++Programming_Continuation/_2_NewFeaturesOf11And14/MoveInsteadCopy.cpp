#include <cstddef>

// using older copying constructor and copying assignment operator
struct OldString {
    OldString() = default;
    OldString(OldString const &s);
    OldString &operator=(OldString const &s);
    OldString(char const *s) {
        size_ = 10;
        data_ = new char(size_);
        for (size_t i = 0; i < size_; ++i)
            *(data_ + i) = *(s + i);
    }
    // ...
private:
    char *data_ = nullptr;
    size_t size_ = 0;
};

OldString getDateStringOld() { // returning by value from function
    OldString date("21.10.2015"); // string is created in dynamic memory
    return date; // here the string is copied for the first time - to the place of invocation
}
/* in old standard we could avoid excess copying by at least two ways:
 * 1 - returning not an object but a pointer to this object from the function
 * 2 - using smart-pointers like unique_ptr
 * also modern compilers can optimize such variants of invocations \
 * передать ссылку/указатель на строку аргументом в функцию и спокойно ее заполнять внутри?
 * - это усложняет интерфейс и требует создавать эту строку заранее.
 * А что насчет memcpy?
 * - для сложных классов это будет опасно.
 */

void showCopying() {
    OldString dateCopied = getDateStringOld(); // here we copy the string for the second time
}

// using new standard's moving constructor and moving assignment operator
struct NewString {
    NewString() = default;
    NewString(char const *s) {
        size_ = 10;
        data_ = new char(size_);
        for (size_t i = 0; i < size_; ++i)
            *(data_ + i) = *(s + i);
    }
    NewString(NewString const &s); // lvalue-reference - copying will be used here
    NewString(NewString &&s) // rvalue reference - moving is used here
            : data_(s.data_), size_(s.size_) {
        s.data_ = nullptr;
        s.size_ = 0;
    }
    NewString &operator=(NewString const &s); // lvalue-reference - copying will be used here
    NewString &operator=(NewString &&s) { // rvalue-reference - moving is used here
        if (this != &s) { // otherwise we'll clear 'this' object's data
            delete[] data_;
            data_ = s.data_;
            size_ = s.size_;
            s.data_ = nullptr; // destructor anyway will be called for 's' object
            s.size_ = 0; // we have to leave 's' object in proper/'agreed' state
        }
        return *this;
    }
    // so we have overloaded versions of constructors - and compiler will choose needed one \
    // rvalue-refs and lvalue-refs are different arguments for compiler
//    char *data() const { return data_; }
//    size_t size() const { return size_; }
private:
    char *data_ = nullptr;
    size_t size_ = 0;
};

#include <utility>

NewString getDateStringNew() {
    NewString date("21.10.2015");
    return std::move(date); // instruction to compiler to use moving instead of copying
    /* при возвращении локального объекта функции (каким и является date) по значению
     * будет вызываться перемещающий конструктор. Т.е. код функции можно было оставить без изменения:
     * // без std::move
            return date; // date будет перемещена
    Более того, такой код потенциально работает более эффективно:
    так как в данном случае компилятору позволяется сделать оптимизацию возвращаемого значения (RVO).
Вот неполный список случаев, когда будут вызываться перемещающие методы:

- если передавать в них объект при помощи std::move();
- если передавать в них временный объект;
- если из функции по значению возвращается локальный объект функции.
     */
}

void showMoving() {
    NewString dateMoved = getDateStringNew();
    // on this invocation compiler chooses moving constructor as it knows about rvalue-ref type
}

// this sample is equal to previous NewString but with using 'swap':
struct String {
    void swap(String &s) { // remember that implicitly a method has access to 'this' object
        std::swap(data_, s.data_);
        std::swap(size_, s.size_);
    }
    void clear() {
        data_ = nullptr;
        size_ = 0;
    }
    String(char const *s) {
        size_ = 10;
        data_ = new char(size_);
        for (size_t i = 0; i < size_; ++i)
            *(data_ + i) = *(s + i);
    }
    String(String const &s);
    String(String &&s) {
        // before invoking 'swap' this object is defined as we have default values
        swap(s);
    }
    String &operator=(String const &s);
    String &operator=(String &&s) {
        clear(); // taking care of 'this' object's state - it'll be sent to 's' via 'swap'
        swap(s);
        return *this;
    }
/* Очистку объекта лучше всего поручить деструктуру:
    String& operator=(String && s) {
        String temp(std::move(s));
        this->swap(temp);
        return *this;
    }
*/
private:
    char *data_ = nullptr;
    size_t size_ = 0;
};

int main() {
    String("aga");
    String a(String("hello")); // moving - inner object is temporary - rvalue
    String b(std::move(a)); // moving - because std::move is used
    String c(a); // copying - because inner object is a lvalue
    a = b; // copying - because right value is a reference
    b = std::move(c); // moving - because std::move is used
    c = String("world"); // moving - because inner value is temporary - rvalue
}

/* конструктор и оператор перемещения используются повсеместно.
 * Может быть вы даже сами его неявно использовали, но не осознавали этого. Пример:

std::string very_complex_function()﻿{
  std::string result;
  // Заполняем result данными.
  return ﻿result;
}

std::string str =﻿very_complex_function();
// Будет вызван конструктор перемещения,
// т.к. любое возвращаемое функцией значение является﻿rvalue reference (ссылки и указатели не в счёт, разумеется).
// Что-нибудь делаем с str.

str = very_complex_function();
// Будет вызван оператор перемещения.
﻿
И да, конструктор и оператор перемещения можно вызвать явно с помощью std::move:
std::string s0 ﻿= "Hello";
std::string s1 = s0;            // Копирование.
std::string s2 = std::move(s0); // Перемещение.
 */