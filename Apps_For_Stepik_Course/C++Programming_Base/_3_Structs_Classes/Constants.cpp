#include <iostream>
using namespace std;

double const pi = 3.1416;

unsigned const secondsInDay = 24 * 60 * 60;

unsigned const daysInAllMonths[12] = {31, 28, 31, 30, 331, 30, 31, 31, 30, 31, 30, 31};

void testEverything()
{
    unsigned *february = (unsigned *)&daysInAllMonths[1]; // in fact here we attempt to cast pointers: const unsigned* -> unsigned*
    *february = 42;                                       // this could be possible but const before array definition prevents this
    cout << *february << endl;

    int a = 10;

    // pointer to constant:
    const int *p1 = &a; // int is constant - not pointer to this int
    int const *p2 = &a; // the same as before
    // *p1 = 0; // this will break - as we're trying to change constant
    p2 = 0; // this will work as pointer itself is not a constant

    // constant pointer:
    int *const p3 = &a;
    *p3 = 30; // this works because value a is not constant here
    // p3 = 0; // impossible to change constant pointer

    // constant pointer to constant:
    int const *const p4 = &a;
    // *p4 = 30; // cannot change constant under pointer
    // p4 = 30; // cannot change constant pointer itself

    // REMEMBER: "const" affect what is to the left of it:
    int *p = &a;
    // int const **pp1 = &p; // pointer to pointer to constant int - but this gives error: invalid conversion from ‘int**’ to ‘const int**’
    int *const *pp2 = &p; // pointer to constant pointer to int
    int **const pp3 = &p; // constant pointer to pointer to int
    // nice thing is to be able to read from right to left in declarations

    // HINT: стандартом разрешены (неявные) преобразования от T* к T const*, но не T** к T const**
    // Вопрос: как с помощью преобразования вида T** к T const** можно было бы изменить константные данные (если бы C++ позволял такие преобразования)?
    int const constantValue = 1;
    int *ptrToConst = 0;
    // ptrToConst = &constantValue; // не скомпилируется, т.к. это преобразование int const * -> int *

    // В этой строке происходит запрещённое преобразование int ** -> int const **
    int const **pp = (int const **)&ptrToConst; // теперь *pp указывает на переменную ptrToConst

    // следующая строка скомпилируется, т.к. *pp имеет тип int const*
    *pp = &constantValue; // это соответствует p = &constantValue
    *ptrToConst = 2;      // изменяем значение переменной constantValue

    cout << constantValue << endl;

    int const c = 10;
    int *pc = (int *)&c;
    cout << ++(*pc) << endl; // gives 11 but c in fact still is 10
}

int main()
{
    testEverything();
    return 0;
}