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

// OTHER OPERATORS: assignment, special, brackets, casting, ternary, memory
void useOtherOperators()
{
    //  assignment: =
    //  special:
    //      prefix: * &
    //      postfix: -> ->*
    //      particular: , . ::
    //  brackets: [] ()
    //  casting: (type)
    //  ternary: x ? a : b
    //  memory: new new[] delete delete[]
}

// all operators can be overloaded except 3 of them: . :: and ternary

// SAMPLE OF OVERLOADING OPERATORS:
struct Vector
{
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}
    // if we try to overload operators in class - they would be allowed to have only one parameter
};
Vector operator-(Vector const &v)
{
    return Vector(-v.x, -v.y);
}
Vector operator+(Vector const &v, Vector const &w)
{
    return Vector(v.x + w.x, v.y + w.y);
}
Vector operator*(Vector const &v, int n)
{
    return Vector(v.x * n, v.y * n);
}
Vector operator*(int n, Vector const &v)
{
    return v * n;
}

int main()
{
    useArithmeticOperators();
    useBitOperators();
    useLogicOperators();
    return 0;
}