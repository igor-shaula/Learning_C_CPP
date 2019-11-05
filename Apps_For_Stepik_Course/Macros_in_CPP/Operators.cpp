#include <iostream>
using namespace std;

// MAIN OPERATORS: arithmetic, bit & logic operators:
void useArithmeticOperators()
{
    //  unary:
    //      prefix: + - ++ --
    //      postfix: ++ --
    //  binary: + - * / % += -= *= /= %=
    int a = 10;
    cout << +a << endl;
    cout << -a << endl;

    char c = 'c';
    std::cout << c << std::endl;
    std::cout << +c << std::endl;
}
void useBitOperators()
{
    // unary: ~
    // binary: & | ^ &= |= ^= >> <<
    cout << "(~1): " << (~1) << endl;
    cout << "(1 & 1): " << (1 & 1) << endl;
    cout << "(2 & 1): " << (2 & 1) << endl;
    cout << "(1 | 1): " << (1 | 1) << endl;
    cout << "(2 | 1): " << (2 | 1) << endl;
    cout << "(1 ^ 1): " << (1 ^ 1) << endl;
    cout << "(2 ^ 1): " << (2 ^ 1) << endl;
    cout << "(8 >> 1): " << (8 >> 1) << endl;
    cout << "(4 << 2): " << (4 << 2) << endl;
}
void useLogicOperators()
{
    //  unary: !
    //  binary: && ||
    //  comparison: == != > < >= <=
    // there is no ^ here - because XOR can be replaced with != for boolean types
    // another realization of XOR: (!x==y) || (x==!y) - but it has to be checked
}

int main()
{
    useArithmeticOperators();
    useBitOperators();
    useLogicOperators();
    return 0;
}