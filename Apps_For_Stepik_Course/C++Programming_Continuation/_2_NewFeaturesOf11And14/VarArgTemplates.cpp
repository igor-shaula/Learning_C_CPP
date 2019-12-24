// in C we can pass variable number of arguments into a function using ... for arguments' list \
// the same story is added but for templates \

// in this sample we'll use template varargs for recursive C++ 'printf()' realization:

#include <iostream>
using std::cout;
using std::endl;

// base of recursion:
void myPrintf(char const *s) { // like the next function but without any template arguments
    while (*s) { // till the end of the string
        if (*s == '%' && *(++s) != '%') // we need only one '%' and check for the next symbol
            cout << "error - found one %" << endl;
        cout << *s++; // printing one symbol and preparing to the next loop iteration
    }
}
template<typename T, typename ...Args>
void myPrintf(char const *s, T const &value, Args... args) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            cout << value;
            myPrintf(++s, args...);
            return;
        }
        cout << *s++;
    }
    cout << "error" << endl;
}
/* Мне кажется стоило упомянуть о том, что параметр value в данном контексте инициализируется
* первым параметром списка args, который автоматически изымается из списка параметров args
* и из - за этого он на каждом этапе сокращается на один элемент. Это очень бы на самом деле помогло.
*/
// Здесь фактически используется хвостовая рекурсия,
// это частный случай рекурсии, который неплохо оптимизируется и не должен удлиннять стек.

// Получилось написать довольно интересную функцию,
// которая считывает произвольное количество аргументов произвольного типа из std::cin.
// Например std::cin >> a >> b >> c >> d; Эквивалентно моей функции read(a, b, c, d).

void read() {}

template<typename T, typename... Args>
void read(T &value_, Args &...args_) {
    std::cin >> value_;
    read(args_...);
}

int runRead() {
    int a, b;
    double c, d;
    using std::string;
    string s1, s2;
    read(a, b, c, d, s1, s2);
    //~ std::cin >> a >> b >> c >> d >> d >> s1 >> s2
    std::cout << "a = " << a << '\n'
              << "b = " << b << '\n'
              << "c = " << c << '\n'
              << "d = " << d << '\n'
              << "s1 = " << s1 << '\n'
              << "s2 = " << s2 << '\n';
    int g;
    double f;
    read(f, g);
    std::cout << "f = " << f << '\n'
              << "g = " << g << '\n';
}

int main() {
    myPrintf("asdf%d", 5); // compilation fails if this is uncommented
    cout << endl;
    myPrintf("asdf%d", 5, 3); // compilation fails if this is uncommented
//    runRead();
    return 0;
}