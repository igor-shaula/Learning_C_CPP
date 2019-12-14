/* names in C++ ca be:
 variables and constants
 functions (and methods)
 structures and classes
 templates
 type synonyms (typedefs)
 enums and unions
 namespaces
 */

// in C there is no way to make names unique - that's why people add prefixes to names:
struct XML_Parser;
int XML_GetCurrentLineNumber(XML_Parser *parser);

// the same in C++ code could look like this:
namespace XML {
    struct Parser;
    int GetCurrentLineNumber(Parser *parser);
}
// full names of this struct & function will be:
// XML::Parser;
// int XML::GetCurrentLineNumber(XML::Parser *parser);

// namespaces can be nested:
namespace items {
    namespace food {
        struct Fruit {};
    }
}
// items::food::Fruit;
// со стандарта С++17 упростили синтаксис вложенных пространств имен, т.е. можно будет так:
namespace items::foodNew {
    struct Fruit { /*...*/ };
}

// namespaces can be separated by other block of code - they're not continuous like struct & functions:
namespace weapons { struct Bow {}; }
namespace items {
    struct Scroll {};
    struct Artifact {};
}
namespace weapons { struct Sword {}; } // adding to existing namespace 'weapons'

// Насчет разделения пространств имён:
// такое можно использовать при активном использовании умных указаелей (о них в третьем модуле).
// Вот пример подобного заголовочного файла:
#pragma once
#include <memory>
namespace MyLib {
    class MyClass;
    typedef std::shared_ptr<MyClass> MyClassPtr;
}
// тут можно включить все заголовочные файлы ДАННОЙ библиотеки, от которых класс ниже зависит.
// Даже при циклическом включении файлов указатель на класс успеет определиться,
// и в результате к нему можно будет обращаться как в заголовочных файлах, так и в файлах с кодом.
namespace MyLib {
    class MyClass {
        // определение класса
    };
}

// all classes & structures implicitly define their own namespace of the same name

// operator :: allows to get access to global namespace (top-level namespace):
struct Dictionary {};
namespace items {
    struct Dictionary {}; // local one
    ::Dictionary globalDictionary; // using top-level class - outside of this namespace
}
// searching in any namespace works until any first (not the best) coincidence is found \
// if nothing suitable found - compiler goes to upper level step by step and searches there \
// if nothing is found at the top level / global namespace - compilation error is fired
int f(int i) { return 1; }
namespace inner {
    int f(float f) { return 2; }
    int f(double a, double b) { return 3; }
    namespace innerInner {
        int a = 9;
        int global = f(a); // function f(float) will be invoked - as it's first suitable found
        // this function selection is not the best but compiler will select first and stop searching
    }
}

// there are 2 different senses in using keyword 'using':
namespace ru {
    namespace spb {
        int f(int i) { return 1; }
        int g(int i) { return -1; }
    }
    using namespace spb; // from now on all stuff from this namespace will be available for use
    using spb::f; // only 'f' will be added to code during compilation - this way is much more clean
    // adding more variants (but less suitable) of function 'f' in current namespace:
    int f(float f) { return 2; }
    int f(int a, int b) { return 3; }
    namespace msk {
        int global = f(5); // function from other namespace 'spb' is invoked here - because of 'using'
        // this time all 3 variants of 'f' are available and compiler chooses the most suitable of them
    }
}

// Koenig lookup(search) = argument-dependent lookup or ADL:
namespace cg {
    struct Vector { Vector(int p1, int p2) {}};
    Vector operator+(Vector a, Vector const &b);
}
cg::Vector a(1, 2);
cg::Vector b(3, 4);
cg::Vector c = a + b; // the same as c = operator+(a,b);
cg::Vector d = cg::operator+(a, b); // gives the same result as previous line
// during search of function name at first names from current namespace are viewed \
// but then search goes in namespaces to which function arguments belong

// nameless namespace - in fact name is given during compilation - but only compiler knows it:
namespace { // generated name will be unique
    struct Test { std::string name; };
}
// given above is equivalent to:
namespace $GeneratedName$ {
    struct Test { std::string name; };
}
using namespace $GeneratedName$;
// nameless namespaces can be used instead of 'static' - their effects are the same

/* В языках программирования C и C++ единица трансляции (англ. translation unit)
 * — подаваемый на вход компилятора исходный текст (файл с расширением .c или .cpp)
 * со всеми включёнными в него файлами
 */
// nameless namespace need describing in more details - especially about static and classes