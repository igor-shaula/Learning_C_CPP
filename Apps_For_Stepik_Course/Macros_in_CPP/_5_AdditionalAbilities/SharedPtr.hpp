#ifndef _LEARNING_C_CPP_SHAREDPTR_HPP
#define _LEARNING_C_CPP_SHAREDPTR_HPP

#include <iostream>
#include "Expression.hpp"

using namespace std;

struct SharedPtr {
    explicit SharedPtr(Expression *ptr = nullptr) { // creates different objects
//        cout << "constructor : counter was: " << counter << endl;
        if (ptr != nullptr) {
//            delete refCounter;
            *refCounter = 1;
            if (ptr != ptr_) // this is questionable
                ptr_ = ptr;
//            cout << "constructor : counter is: " << counter << endl;
        }
    }

    SharedPtr(SharedPtr const &other) { // creates COPIES
        if (other.ptr_ != nullptr) {
            *refCounter = *refCounter + 1; // later change to more compact form
            // this has to be the only place of this counter incrementation
            ptr_ = other.ptr_;
        }
    }

    ~SharedPtr() {
        *refCounter = *refCounter - 1;
//        cout << "destructor : counter is: " << counter << endl;
        if (refCounter != nullptr && *refCounter <= 0) {
            delete ptr_; // memory leak emerges if this deletion is absent
            ptr_ = nullptr;
            delete refCounter;
//            cout << "destructor : nullified ptr_" << endl;
        }
    }

    SharedPtr &operator=(SharedPtr const &other) {
        if (ptr_ == other.ptr_) { // is it correct check for assigning to itself ???
            // todo continue here
            cout << "ptr_ == other.ptr_" << endl;
        }
        if (ptr_ != nullptr && refCounter != nullptr && *refCounter > 0) {
            (*refCounter)--;
        }
        if (other.ptr_ != nullptr && other.refCounter != nullptr) {
//        if (other.ptr_ != nullptr && other.refCounter != nullptr && *(other.refCounter) > 0) {
            (*(other.refCounter))++;
        }
    }

    /* method release() is absent in the task */
    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        ptr_ = nullptr;
        if (refCounter != nullptr)
            *refCounter = 0;
        return tmp;
    }

    void reset(Expression *ptr = nullptr) {
        if (refCounter != nullptr && *refCounter == 0) {
            delete ptr_; // memory leak emerges if this deletion is absent
            ptr_ = ptr;
            delete refCounter;
        }
    }

    // these methods don't require to be tested as they are simple getters and setters -------------

    Expression *get() const {
        if (refCounter != nullptr && *refCounter > 1)
            (*refCounter)--;
        return ptr_;
    }

    Expression &operator*() const { return *ptr_; }

    Expression *operator->() const { return ptr_; }

    bool operator==(double const *d) {
        Number n = ptr_->evaluate(); // receiving Expression but can instead use its child - Number
        return n.evaluate() == *d; // comparing real double values got from inside Number class
    }

private:
    Expression *ptr_;
    int *refCounter = new int(0);
    /* counts only different pointers - how many separate instances we have */
};

#endif //_LEARNING_C_CPP_SHAREDPTR_HPP