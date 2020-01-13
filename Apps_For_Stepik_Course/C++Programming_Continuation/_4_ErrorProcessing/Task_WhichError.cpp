#include <stdexcept>

extern bool X = false;

struct MyError : std::runtime_error {
    MyError(char const *s)
            : std::runtime_error(s) {
        if (X)
            throw std::logic_error("Logic error");
    }
};

void foo() {
    throw MyError("My error");
}

int main() {
    foo();
    return 0;
}