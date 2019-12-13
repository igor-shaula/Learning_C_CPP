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