#include <functional>
#include <memory>

// simplest lambda - in correlation to samples from StdFunction.cpp:
std::function<int(int, int)> lambda = [](int x, int y) { return x / y; }; // shorter than IntDiv()

// the same but with pointing of the returned type:
std::function<int(int, int)> lambdaTyped = [](int x, int y) -> int { return x / y; };

// in C++14 type of parameters can be deducted by compiler:
std::function<int(int, int)> lambda14 = [](auto x, auto y) { return x / y; };

// there is a possibility to capture a variable in lambda - inside its []
int total = 0;
//auto addToTotal = [&total](int x) { total += x; }; // 'total' cannot be captured outside of a function
void captureByReference() {
    int localTotal = 0;
    auto addToTotal = [&localTotal](int x) { localTotal += x; }; // but it works inside a function
}
//auto subTotal = [total](int &x) { x -= total; }; // 'total' cannot be captured outside of a function
void captureByValue() {
    int localTotal = 0;
    auto subTotal = [localTotal](int &x) { x -= localTotal; }; // localTotal captured by value
}
// also we can capture 'this' - of course only where it's present - in methods:
struct Any {
    void update() {}
    void captureThis() {
        auto callUpdate = [this]() { this->update(); };
    }
};

int main() {
    captureByReference();
    captureByValue();
    Any().captureThis();
    return 0;
}

/*
 * there are several types of caption:
 * [] - no variable caption
 * [x] - caption by value
 * [&x] - caption by reference
 * [x, &y] - 'x' is captured by value and 'y' is captured by reference
 * [&] - all variables are captured by reference
 * [=] - all variables are captured by value
 * [&, x] - by default all variables are captured by reference and only 'x' - by value
 * [=, &x] - by default all variables are captured by value and only 'x' - by reference
 */

// in C++14 we have moving caption: [x = std:move(y)]

// using default caption like [&] and [=] is a bad idea because it leads to implicit problems:
/*
std::function<bool(int)> getFilter(Checker const &c) const {
    auto d = c.getModulo();
    return [&](int i) { return i % d == 0; } // captured reference to a local variable
    // problem here is that a link to captured & destroyed inner variable is used
}
struct Checker {
    std::function<bool(int)> getFilter() const {
        return [=] (int x) { return x % d == 0; // 'this' is captured here as we're inside a method
        // problem is that in fact we use (x % (this->d) == 0;) instead what is written above
    }
    int d;
}
*/

// В четырнадцатом стандарте можно не только захватить переменную с перемещением,
// но и определить новую локальную переменную лямбда-объекта: https://isocpp.org/wiki/faq/cpp14-language#lambda-captures
// Это позволяет, например, посчитать, сколько раз лямбда была вызвана:﻿

auto lambda14new = [i = 0]() mutable { return ++i; };

// Или создать лямбду, которую нельзя скопировать:

auto lambdaUnique = [i = 0, p = std::make_unique<int>(2)]() mutable { return ++i; };
//auto lambda2 = lambdaUnique; // error

// если у лямбда-выражения в теле не один return, то тип возвращаемого значения надо явно указывать

// захват значений и получение аргументов происходят в разных местах программы.
// При создании лямбды можно захватить значение, которое нельзя передать как аргумент,
// кроме того, оно будет доступно всем вызовам лямбды.