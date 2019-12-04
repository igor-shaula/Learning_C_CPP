#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

/*
 * По аналогии с вашим примером пытаюсь создать обобщенную функцию
 * которая на вход принимает контейнер с числами произвольного типа
 * и на выход выдаёт контейнер состоящий из строк. Т.е { 1, 2, 3, } -> { "1", "2", "3" }.
 */

template<typename ValueType,
        template<class T, class Allocator = std::allocator<T>> class Container>
Container<string> toStrings(Container<ValueType> const &inContainer_) {
    Container<string> outContainer(inContainer_.size());
    typename Container<ValueType>::const_iterator itIn = begin(inContainer_);
    typename Container<string>::iterator itOut = begin(outContainer);
    while (itIn != end(inContainer_)) {
        *itOut = to_string(*itIn);
        ++itIn;
        ++itOut;
    }
    return outContainer;
}

int main() {
    vector<int> inArr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<std::string> outArr(toStrings(inArr));
    list<double> inList{1.1, 2.2, 3.3};
    list<std::string> outList(toStrings(inList));
}