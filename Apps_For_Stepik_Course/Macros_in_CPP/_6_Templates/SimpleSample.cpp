#include "SimpleSample.hpp"

ARRAY_OVER_MACRO(ArrayInt, int);

ARRAY_OVER_MACRO(ArrayFloat, float);

int main() {
    /* before using - we must define these template-like types here */
    ArrayInt ai(9);
    ArrayFloat af(9);
    /* as for real templates - we can declare & define them immediately where we want */
    Array<int> ait(9);
    Array<float> aft(9);
    return 0;
}