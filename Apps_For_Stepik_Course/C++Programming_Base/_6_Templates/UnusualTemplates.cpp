/* template parameters can be:
 * types, - that's already well known
 * int values, - must be defined during compilation time - that's why setting a dimension to an array begin to matter
 * pointers or references with external linking, - must be either global variables or static field of class
 * other templates - we can just wrap one template into another like a type
 */

#include <cstddef>
#include <iostream>

using namespace std;

// sample of using integer values as parameters - matrix multiplication:
template<class T, size_t N, size_t M> // N and M must be already known at compile time
struct Matrix {
    // ...
    T &operator()(size_t i, size_t j) { return data_[M * j + i]; }
private:
    T data_[N * M];
};
// as we know - only matrix with equal dimensions can be multiplied - so we define this rule by setting types (M)
template<class T, size_t N, size_t M, size_t K>
Matrix<T, N, K> operator*(Matrix<T, N, M> const &a, Matrix<T, M, K> const &b);

// using refs as template types - having different files as templating parameters for a logger
template<ostream &log>
struct FileLogger {
    FileLogger() { log << "Logging started.\n"; }
    ostream &PutRecord(string const &record) { return log << record; }
    ~FileLogger() { log << "Logging finished.\n"; }
};

int main() {
    FileLogger<cout> fl1;
    FileLogger<cout> fl2;
    // here we using only one cout as parameter - but it's better anyway than nothing
    fl1.PutRecord("Logging to fl1\n");
    fl1.PutRecord("Logging to fl2\n");
    return 0;
}