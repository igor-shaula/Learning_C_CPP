/* TASK 1 / SIMILAR FUNCTIONS - review all options of generalizing a function to multiply ints and floats ------------*/

#include <cstddef>

/* 1 - good old C */
int squareI(int x) { return x * x; }
float squareF(float x) { return x * x; }
// the point is that in C there iS No overloading - two functions anyway must differ by their names

/* 2 - plain C++ */
int square(int x) { return x * x; }
float square(float x) { return x * x; }
// in somewhat better than in C because in C++ we can use overloading but still there is duplication of code

/* 3 - OOP C++ - almost like Java */
struct INumber {
    virtual INumber *multiply(INumber *x) const = 0;
};
struct Int : INumber {
    // wraps primitive int
};
struct Float : INumber {
    // wraps primitive float
};
INumber *square(INumber *x) { return x->multiply(x); }
// too much code for OOP style, also this approach looks way more complex and hard to read \
// by the way as we use pointers and dynamic memory here - this OOP code will work slower

/* 4 - C++ templates */
template<typename Num>
Num square(Num x) { return x * x; }
// this will work for any type with defined operator of multiplying

/* TASK 2 / SORTING --------------------------------------------------------------------------------------------------*/

/* 1 - good old C */
void qsort(void *base, size_t nItems, size_t size /* , pointer to sorting function */);
// this function is standard & hence not type-safe as anything else in C

/* 2 - plain C++ */
void sort(int *p, int *q);
void sort(float *p, float *q);
// code duplication here

/* 3 - OOP C++ */
struct IComparable {
    virtual int compare(IComparable *comparable) const = 0;
    virtual ~IComparable() = 0;
};
void sort(IComparable **p, IComparable **q);
// this code will work slower as it has to use dynamic memory

/* 4 - C++ templates */
template<typename Type>
void sort(Type *p, Type *q);

int main() {
    return 0;
}