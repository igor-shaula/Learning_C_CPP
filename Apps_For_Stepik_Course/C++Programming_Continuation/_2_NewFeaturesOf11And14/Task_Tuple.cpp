#include <tuple>

//template<typename T1, typename T2, typename T3>
//typedef std::tuple<T1, T2, T3> tuple;

//template<typename T1, typename T2, typename T3>
//std::pair<int, int> to_pair(tuple t) {}
//
//template<>
//std::pair<int, int> to_pair<int, int>(tuple t) {
//    return std::make_pair(std::get<1>(t), std::get<2>(t));
//}

/*
template<typename T1, typename T2, typename T3, typename R, typename Q>
auto
to_pair(std::tuple<T1, T2, T3> t) -> decltype(std::pair<R, Q>(std::get<1>(t), std::get<2>(t))) {
    return std::pair<R, Q>(std::get<1>(t), std::get<2>(t)); // OR make_pair() ?
}
*/

//template<int i1, int i2>
//template<int i1, int i2, typename Tuple, typename T1, typename T2>
//std::pair<T1, T2>
//to_pair(Tuple t)/* -> decltype(std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t))) */{
////auto to_pair(Tuple t) -> decltype(std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t))) {
//    return std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t)); // make_pair() OR pair() ???
//}

template<size_t i1, size_t i2>
auto to_pair(std::tuple<> t) -> decltype(std::make_pair(std::get<i1>(t), std::get<i2>(t))) {
//auto to_pair(std::tuple<> t) -> decltype(std::make_pair(std::get<size_t>(t), std::get<size_t>(t))) {
    return std::make_pair(std::get<i1>(t), std::get<i2>(t));
}

//template<int i1, int i2, typename Tuple>
//auto to_pair(Tuple t) -> decltype(std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t))) {
//    return std::make_pair<T1, T2>(std::get<i1>(t), std::get<i2>(t)); // OR pair() ?
//}

//template<typename Tuple>
//struct Helper {
//    Helper operator<(int a) {}
//    typedef decltype(to_pair(Tuple t
//    ))
//    type;
//    type operator>(int a) {}
//    Helper operator,(int a) {};
//};

//Helper operator<(Helper a, int b) {}

void testNeededFunction() {
    auto t = std::make_tuple(0, 3.5, "Hello");
//    Helper to_pair;
//    std::pair<double, char const *> p = to_pair<1, 2>(t);
    // p содержит 3.5 и "Hello"
}

int main() {
    testNeededFunction();
    return 0;
}

//template<typename T1, typename T2>
//void foo(int a, int b) {}
//template<>
//void foo<int, int>(int a, int b) { cout << "specialized only for ints" << endl; }