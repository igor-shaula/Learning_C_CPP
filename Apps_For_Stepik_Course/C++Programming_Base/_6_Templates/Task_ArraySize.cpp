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

void givenTests() {
    int ints[] = {1, 2, 3, 4};
    double doubles[] = {3.14};
    int *iptr = ints;
    array_size(ints); // вернет 4
    array_size(doubles); // вернет 1
//    array_size(iptr); // тут должна произойти ошибка компиляции
}
int main() {
    return 0;
}