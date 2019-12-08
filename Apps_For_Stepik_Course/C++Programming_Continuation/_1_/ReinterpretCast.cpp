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