#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "hicpp-use-equals-delete"
#ifndef _LEARNING_C_CPP_SCOPEDPTR_HPP
#define _LEARNING_C_CPP_SCOPEDPTR_HPP

#include <iostream>
#include "Expression.hpp"

using namespace std;

struct ScopedPtr {
    explicit ScopedPtr(Expression *ptr = nullptr) {
//        cout << "constructor : counter was: " << counter << endl;
        if (ptr != nullptr && ptr_ != ptr) {
            ptr_ = ptr;
//            cout << "constructor : counter is: " << counter << endl;
        }
    }

    ~ScopedPtr() {
//        cout << "destructor : counter is: " << counter << endl;
        if (ptr_ != nullptr) {
            delete ptr_; // memory leak emerges if this deletion is absent
            ptr_ = nullptr;
//            cout << "destructor : nullified ptr_" << endl;
        }
    }

    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }

    void reset(Expression *ptr = nullptr) {
        delete ptr_; // memory leak emerges if this deletion is absent
        ptr_ = ptr;
    }

    // these methods don't require to be tested as they are simple getters and setters -------------

    Expression *get() const { return ptr_; }

    Expression &operator*() const { return *ptr_; }

    Expression *operator->() const { return ptr_; }

    bool operator==(double const *d) {
        Number n = ptr_->evaluate(); // receiving Expression but can instead use its child - Number
        return n.evaluate() == *d; // comparing real double values got from inside Number class
    }

private:
    ScopedPtr(const ScopedPtr &);

    ScopedPtr &operator=(const ScopedPtr &);

    Expression *ptr_;
};

#endif //_LEARNING_C_CPP_SCOPEDPTR_HPP
#pragma clang diagnostic pop