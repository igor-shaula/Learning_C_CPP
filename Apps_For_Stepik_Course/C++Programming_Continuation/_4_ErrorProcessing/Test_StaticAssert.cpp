#include <type_traits>
using namespace std;

template<class T>
void test() {
    static_assert(std::is_arithmetic<T>::value ||
                  (std::is_pointer<T>::value &&
                   std::is_class<typename std::remove_pointer<T>::type>::value),
                  "T can not be used here");
}

#include <vector>
#include <iostream>
int main() {
    test<int>();
//    test<int *>();
//    test<vector<int>>();
//    test<vector<int*>>();
//    test<string>();
    test<string *>();
    return 0;
}