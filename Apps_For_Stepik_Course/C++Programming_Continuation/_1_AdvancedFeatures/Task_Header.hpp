#ifndef C_PROGRAMMING_CONTINUATION_TASK_HEADER_HPP
#define C_PROGRAMMING_CONTINUATION_TASK_HEADER_HPP

#include <string>
#include <iostream>
using std::cout;
using std::endl;

namespace {
    struct Test {
        std::string data;
    };
    inline void foo() { cout << "foo" << endl; }
    static void bar() { cout << "bar" << endl; } // keyword 'static' can be removed from here
    void foobar() { cout << "foobar" << endl; }
}

#endif //C_PROGRAMMING_CONTINUATION_TASK_HEADER_HPP

/* тут главное понимать, что код из заголовочного файла фактически копируется в cpp-файл,
 * и после этого начинается компиляция. Поэтому имя безымянного пространства имен генерируется 3 раза
 * - и получается 3 разных пространства имен для каждого файла \
 * foobar() в безымянном пространстве имен, соответственно в каждой единице трансляции у нее разные имена
 *
 * Что даёт static, если уже есть namespace, как его замена?
 * - обеспечивает функции внутреннюю линковку.
 * а безымянный namespace не обеспечивает?
 * - зависит от стандарта. В C++03 - нет, в C++11 - да.
 *
 * Можно получить указатель на что-то в одной единице трансляции и передать в другую.
 * Например, передав указатель на локальную переменную как параметр в функцию из другой единицы трансляции.
 * Вопрос, можно ли так сделать со статической функцией bar.
 *
 * Помог вывод адресов функций в тестовой программе для всех трёх файлов в тестовой программе:
 * cout << int(&func_name) << endl;
 *
 * Помогла сборка программы:
 *      g++ file*.cpp -o prog
 * и просмотр ее имен с помощью nm
 *      nm prog
 *
 * Для практики можно использовать g++ -S file1.cpp -o outFile.cpp.
 * Опция -S остановит процесс сборки после компиляции, и можно будет посмотреть какие функции в нее включились.
 * т.к. inline-функция не отработает(условие задания), можно объявить ее просто без inline (это чтобы посмотреть результат)
 */