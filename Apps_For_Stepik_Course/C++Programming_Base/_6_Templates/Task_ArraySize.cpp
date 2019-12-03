#include <cstddef>
/*
 * Реализуйте функцию array_size, которая возвращает размер массива, переданного в качестве параметра.
 * Функция должна работать только для массивов!
 * Т. е. если функции передать указатель, должна произойти ошибка компиляции.
 */

template<typename T, size_t N>
size_t array_size(T (&array)[N]) {
    return N;
} // yes i did it myself in a few minutes and from the first attempt !!

void runGivenTests() {
    int ints[] = {1, 2, 3, 4};
    double doubles[] = {3.14};
    int *iptr = ints;
    array_size(ints); // вернет 4
    array_size(doubles); // вернет 1
//    array_size(iptr); // тут должна произойти ошибка компиляции
}
void runExamples();
int main() {
    runGivenTests();
    runExamples();
    return 0;
}

// ADDITION ----------------------------------------------------------------------------------------

#include "iostream"
using namespace std;

template<typename T, size_t N>
void View(const T(&arr)[N]) {
    for (size_t i = 0; i < N; ++i)
        cout << (arr)[i] << ", ";
    cout << "\b\b \n";
}

template<typename T, size_t N>
void View(const T(*arr)[N]) {
    for (size_t i = 0; i < N; ++i)
        cout << (*arr)[i] << ", ";
    cout << "\b\b \n";
}

void runExamples() {
    cout << endl << "------ Examples ------" << endl;
    int ar1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float ar2[] = {0.5f, 2.5f, 4.5f, 6.5f, 8.5f, 10.5f, 12.5f};
    View(ar1);
    View(&ar2);
    // А здесь мы ещё имеем возможность узнать размер массива вызвав метод size
}