// Дополните класс Array перемещающим конструктором и перемещающим оператором присваивания.

#include <cstddef>
#include <utility>

template<class T>
struct Array {
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0);
    Array(Array const &a);
    Array &operator=(Array const &a);
    ~Array();

    size_t size() const;
    T &operator[](size_t i);
    T const &operator[](size_t i) const;

    void swap(Array &other) {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    // реализуйте перемещающий конструктор
    Array(Array &&other) {
        size_ = 0;
        data_ = nullptr;
        swap(other);
    }

    // реализуйте перемещающий оператор присваивания
    Array &operator=(Array &&other) {
        if (this != &other) {
            size_ = 0;
            delete data_;
            swap(other);
        }
        return *this;
    }

private:
    size_t size_;
    T *data_;
};