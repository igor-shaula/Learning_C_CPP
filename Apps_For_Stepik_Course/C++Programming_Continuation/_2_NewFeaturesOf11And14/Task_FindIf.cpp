#include <functional>
#include <iostream>
using namespace std;

template<class F>
int *find_if(int *p, int *q, F gen_finder) {
    for (; p != q; ++p)
        if (gen_finder(*p))
            return p;
    return q;
}
/*
 * Определите переменную gen_finder,
 * хранящую безымянную функцию,
 * которая принимает массив значений типа int через два указателя
 * и возвращает безымянную функцию,
 * которая в свою очередь принимает значение типа int
 * и проверяет, есть ли это значение в переданном массиве.
 */

auto gen_finder = [](int *inner, int *innerBorder) {
    return [=](int outerValue) -> bool {
//        cout << "outerValue from gen_finder = " << outerValue << endl;
        return outerValue == *find_if(inner, innerBorder, [=](int innerValue) -> bool {
//            cout << "\tinnerValue from gen_finder = " << innerValue << endl;
            return outerValue == innerValue;
        });
        // in fact we need two for-loops to find cross value
    };
};

void runGivenTest() {
    int primes[5] = {2, 3, 5, 7, 11};
    int m[10] = {0, 0, 1, 1, 4, 6, 7, 8, 9, 10};
    // in fact the task here is to find a value that is present in both arrays
    int *first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
    // first_prime будет указывать на число 7
    cout << *first_prime << endl;
}

int main() {
    runGivenTest();
    return 0;
}