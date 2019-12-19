#include <functional>

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