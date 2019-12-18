#include <initializer_list>

// easy ability to pass a list of values into a function
template<typename T>
struct Array {
    Array(std::initializer_list<T> list) {}
};

// initializer_list can be used for functions as well:
int sum(std::initializer_list<int> list) {
    int result = 0;
    for (int x : list)
        result += x;
    return result;
}

int main() {

    Array<int> primes = {2, 3, 5, 7, 11, 13, 17}; // values can be passed only in this form: {...}

    int s = sum({1, 1, 2, 3, 5, 8, 13, 21}); // note that {...} is passed as an argument

    return 0;
}