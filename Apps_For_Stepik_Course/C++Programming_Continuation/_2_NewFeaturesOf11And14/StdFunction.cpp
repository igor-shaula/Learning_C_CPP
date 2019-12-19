#include <functional>

// there is a class for containing functions - std::function \
// it's universal for keeping pointers to functions, pointers to methods an functional objects \\

// let's say we have a function:
int mult(int x, int y) { return x * y; }
// ... and overloaded operator () that is a method of a class:
struct IntDiv {
    int operator()(int x, int y) const { // const - arguments 'x' and 'y' don't change here
        return x / y;
    } // actual using of this operator on class will resemble function/constructor call: IntDiv();
};

void showStdFunctionUse(char const OP) {
    std::function<int(int, int)> operation; // in <> as usual: return type & parameters' types
    if (OP == '*') {
        operation = &mult; // note that function here is used WITHOUT () - only by its name
    } else if (OP == '/') {
        operation = IntDiv(); // looks like constructor invocation - but in fact is a method
    }
    int result = operation(7, 8);
}

int main() {
    showStdFunctionUse('*');
    showStdFunctionUse('/');
    return 0;
}

// note that std::function allows us to work with pointers to methods as well \\