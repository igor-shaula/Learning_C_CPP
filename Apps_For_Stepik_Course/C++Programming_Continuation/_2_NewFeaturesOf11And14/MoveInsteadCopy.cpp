#include <cstddef>

// using older copying constructor and copying assignment operator
struct OldString {
    OldString() = default;
    OldString(OldString const &s);
    OldString &operator=(OldString const &s);
    OldString(char const *s) {
        size_ = 10;
        data_ = new char(size_);
        for (size_t i = 0; i < size_; ++i)
            *(data_ + i) = *(s + i);
    }
    // ...
private:
    char *data_ = nullptr;
    size_t size_ = 0;
};

OldString getDateString() { // returning by value from function
    OldString date("21.10.2015"); // string is created in dynamic memory
    return date; // here the string is copied for the first time - to the place of invocation
}
/* in old standard we could avoid excess copying by at least two ways:
 * 1 - returning not an object but a pointer to this object from the function
 * 2 - using smart-pointers like unique_ptr
 * also modern compilers can optimize such variants of invocations \
 * передать ссылку/указатель на строку аргументом в функцию и спокойно ее заполнять внутри?
 * - это усложняет интерфейс и требует создавать эту строку заранее.
 * А что насчет memcpy?
 * - для сложных классов это будет опасно.
 */

void showCopying() {
    OldString dateCopied = getDateString(); // here we copy the string for the second time
}

// using new standard's moving constructor and moving assignment operator
struct NewString {
    NewString() = default;
    NewString(NewString &&s) // instead of OldString(OldString const &s); also && - rvalue reference
            : data_(s.data_), size_(s.size_) {
        s.data_ = nullptr;
        s.size_ = 0;
    }
    NewString &operator=(NewString &&s) {
        if (this != &s) { // otherwise we'll clear 'this' object's data
            delete[] data_;
            data_ = s.data_;
            size_ = s.size_;
            s.data_ = nullptr; // destructor anyway will be called for 's' object
            s.size_ = 0; // we have to leave 's' object in proper/'agreed' state
        }
        return *this;
    }
//    char *data() const { return data_; }
//    size_t size() const { return size_; }
private:
    char *data_;
    size_t size_;
};