#include <exception>
#include <string>
#include <stdexcept>
using namespace std;

extern bool X = false;
extern bool Y = true;

// these 4 declarations were added by me to compile other given code
void foo();
void bar();
void log(string s, char const *what) {};
struct B {};

struct A {
    A() {}
    ~A() {
        try {
            bar();
        } catch (std::exception const &e) {
            log("~A()", e.what());
        }
    }
    B b;
};

void foo() {
    A a;
    if (X)
        throw std::runtime_error("Some message");
}

void bar() {
    if (Y)
        throw std::logic_error("Some message");
}

int main() {
    foo();
    return 0;
}