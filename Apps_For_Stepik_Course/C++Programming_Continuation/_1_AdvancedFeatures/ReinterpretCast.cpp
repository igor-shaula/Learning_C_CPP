// reinterpret_cast<> is used for conversion of NON-related types \
// it can be used for different interpretation of existing data \
// it does not shift pointer as static_cast<> can do - here pointer value stays the same \
// for example we can serialize-deserialize data with reinterpret_cast<> \
// additionally reinterpret_cast<> can help to transform pointer to integer ang vise versa

#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

// sample of super-simple API for transporting data over network - byte by byte:
void send(char const *data, size_t length) {
    cout << "sending..." << endl;
}
char *receive(size_t *length) { // length is received as well - inner pointer is not const
    cout << "receiving..." << endl;
    auto *m = static_cast<double *>(malloc(sizeof(double) * 100)); // array of doubles
    m[0] = 1.2;
    char *mc = reinterpret_cast<char *>(m);
    return mc;
} // implementation of this function was not required - it exists only for compilation purpose

void showSending() {
    auto *m = static_cast<double *>(malloc(sizeof(double) * 100)); // array of doubles
    m[0] = 1.2;
    char *mc = reinterpret_cast<char *>(m); // from our type to bytes - but content stays the same
    send(mc, sizeof(double) * 100); // 800 bytes in total
}

void showReceiving() {
    size_t length = 0;
    auto *m = reinterpret_cast<double *>(receive(&length)); // from bytes to our type
    length = length / sizeof(double); // here we have just set length - it must not be 0
    cout << m[0] << endl;
}

void showConversionOfPointer() {
    auto *m = new double(2.3);
    auto ms = reinterpret_cast<size_t>(m);
    cout << ms << endl;
}

int main() {
    showSending();
    showReceiving();
    showConversionOfPointer();
    return 0;
}

/*
 * Первый пример при работе с send и receive вышел не очень удачным,
 * потому что в данном случае существует общеизвестный и более безопасный трюк
 * с применением двойного static_cast﻿ для случаев с преобразованием указателей через void*:
    char* mc = static_cast<char*>(static_cast<void*>(m));

    использование reinterpret_cast сродни использованию молотка — не безопасно,
    да ещё и по рукам попасть можно. В C++ есть некоторые моменты,
    где в силу тех или иных обстоятельств приходится использовать эту конструкцию,
    но в общем случае стоит минимизировать использование reinterpret_cast.
    Потому что (1) это широкое поле для получение Undefined Behavior,
    (2) трудно отлаживать такой код, (3) могут возникнуть проблемы с переносимостью программы.
    В отличие от reinterpret_cast преобразование static_cast проверяется на этапе компиляции,
    ввиду чего мы получим ошибку компиляции, если преобразование недопустимо.
 */