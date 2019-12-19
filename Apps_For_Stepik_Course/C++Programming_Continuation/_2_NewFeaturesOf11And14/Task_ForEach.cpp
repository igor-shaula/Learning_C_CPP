#include <functional>
#include <iostream>
using namespace std;

template<class F>
void for_each_int(int *p, int *q, F f) {
    for (; p != q; ++p)
        f(*p);
}
// Определите переменную square_fun, хранящую безымянную функцию, которая возводит переданное число в квадрат.

std::function<int(int &)> square_fun = [](int &x) -> int { x *= x; };
auto square_fun_auto = [](int &x) -> int { x *= x; }; // the same effect as lambda above

void print(int const array[]) {
    for (size_t i = 0; i != 10; ++i)
        cout << array[i] << ' ' << endl;
}

void runGivenTest() {
    int m[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for_each_int(m, m + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};
    print(m);
}

int main() {
    runGivenTest();
    return 0;
}