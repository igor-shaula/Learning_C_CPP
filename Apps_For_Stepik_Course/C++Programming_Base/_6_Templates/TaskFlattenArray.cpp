#include "TaskFlattenArray.hpp"

void testAllVariants();
int main() {
    testAllVariants();
    return 0;
}
void testAllVariants() {
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout); // выводит на экран строку "10 20"
    Array<Array<int> > array_of_ints(2, ints);
    flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"
    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout); // работать должно не только для типа int
}