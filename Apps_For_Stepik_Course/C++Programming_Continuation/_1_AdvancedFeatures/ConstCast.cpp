#include <cstddef>

// implicit conversion for adding constancy does not require anything - it will compile and work \
// operator const_cast<> is used for addition(implicit) and removal of 'const' behavior \
// always try to avoid const_cast<> because it's a sign of bad design in code \
// almost only exclusion is realizing setter via getter - avoiding duplication of code:
struct T {
    T &operator[](size_t i) { // setter
        return const_cast<T &>(
                const_cast<T const &>(
                        /*
                         * Этот каст относится к (*this). Если сначала не добавить константность,
                         * то неконстантный метод внутри себя вызовет самого себя, а не константный.
                         * Получим бесконечную рекурсию.
                         */
                        *this
                )[i]
        );
    }
    T const &operator[](size_t i) const { //getter
//        assert(i < size_);
        return data_[i];
    }
private:
    T *data_;
};

/*
 * На практике const_cast используется в основном для работы с легаси кодом,
 * где константные по своей природе ссылки не обозначены как const.
 * Но что делать с ссылками на immutable объекты? ( классы которые нельзя изменить после создания).
 * Писать const или нет? По логике если класс immutable то указание const является лишь синтаксическим мусором.
 * Если не предполагается, что класс меняется, то это должно быть видно невооружённым глазом.
 * Тем более, что у константных ссылок есть преимущество, что по ним можно передать временный объект.
 */

#include <iostream>
using namespace std;

class ArrayInt {
    int *data_;
    size_t size_;
public:
    explicit ArrayInt(size_t size) : data_(new int[size]), size_(size) {}
    ~ArrayInt() { delete[] data_; }
    size_t size() const { return size_; }
    const int &operator[](size_t i) const { return data_[i]; }
    int &operator[](size_t i) {
        return const_cast<int &>(static_cast<const ArrayInt &>(*this)[i]); // attention to here !!!
        // inner const_cast replaced by static_cast - "Эффективное использование С++. 55 верных советов."
    }
};

int main() {

    ArrayInt a(10);
    const ArrayInt b(10);

    a[0] = 200;

    std::cout << a[0] << std::endl;
    std::cout << b[0] << std::endl;

    return 0;
}