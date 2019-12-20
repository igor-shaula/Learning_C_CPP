#include <tuple>
#include <iostream>
using namespace std;

/*
template<typename T1, typename T2, typename T3, typename R, typename Q>
auto to_pair(std::tuple<T1, T2, T3> t) -> decltype(std::pair<R, Q>(std::get<1>(t), std::get<2>(t))) {
    return std::pair<R, Q>(std::get<1>(t), std::get<2>(t)); // OR make_pair() ?
}

template<int i1, int i2, typename Tuple, typename T1, typename T2>
auto to_pair(Tuple t) -> decltype(std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t))) {
    return std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t)); // OR pair() ?
}

template<int i1, int i2, typename Tuple, typename T1, typename T2>
std::pair<T1, T2> to_pair(Tuple t)*/
/* -> decltype(std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t))) *//*
{
//auto to_pair(Tuple t) -> decltype(std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t))) {
    return std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t)); // make_pair() OR pair() ???
}
*/

// based on two arguments passed from to_pair<1, 2>(t); --------------------------------------------

// this variant is the best - it compiles and works at least
template<size_t i1, size_t i2>
auto to_pair(std::tuple<int, double, const char *> t) -> decltype(
//auto to_pair(std::tuple<decltype(std::make_tuple(0, 3.5, "Hello"))> t) -> decltype(
std::make_pair(std::get<i1>(t), std::get<i2>(t))) {
    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;
    return std::make_pair(std::get<i1>(t), std::get<i2>(t));
}

/*
template<int i1, int i2>
auto to_pair(std::tuple<> t) -> decltype(std::make_pair(std::get<int>(t), std::get<int>(t))) {
    return std::make_pair(std::get<i1>(t), std::get<i2>(t));
}

template<size_t i1, size_t i2>
auto to_pair(std::tuple<> t) -> decltype(std::make_pair(std::get<i1>(t), std::get<i2>(t))) {
    return std::make_pair(std::get<i1>(t), std::get<i2>(t));
}

template<size_t i1, size_t i2>
auto to_pair(std::tuple<> t) -> decltype(std::make_pair(std::get<size_t>(t), std::get<size_t>(t))) {
    return std::make_pair(std::get<i1>(t), std::get<i2>(t));
}
*/

void testNeededFunction() {
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const *> p = to_pair<1, 2>(t);
    // p содержит 3.5 и "Hello"
    cout << std::get<0>(p) << ' ' << std::get<1>(p) << endl;
}

int main() {
    testNeededFunction();
    return 0;
}

//template<typename T1, typename T2>
//void foo(int a, int b) {}
//template<>
//void foo<int, int>(int a, int b) { cout << "specialized only for ints" << endl; }