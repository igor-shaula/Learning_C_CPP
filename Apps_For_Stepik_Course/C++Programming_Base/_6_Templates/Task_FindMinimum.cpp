#include "Task_FindMinimum.hpp"
#include "iostream"

using namespace std;

void testAll();
int main() {
    testAll();
    return 0;
}
void testAll() {
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less); // в min должно попасть число 2
    int max = minimum(ints, Greater()); // в max должно попасть число 15
}