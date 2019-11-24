#ifndef _LEARNING_C_CPP_SHAREDPTR_HPP
#define _LEARNING_C_CPP_SHAREDPTR_HPP

#include <iostream>
#include "Expression.hpp"

using namespace std;

struct SharedPtr {
    explicit SharedPtr(Expression *ptr = nullptr) { // creates different objects
//        cout << "constructor : counter was: " << counter << endl;
        if (ptr != nullptr) {
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
        safeDecRefCounter();
        safeDeleteRefCounterIfNeeded();
//        cout << "destructor : counter is: " << counter << endl;
        if (ptr_ != nullptr) {
//            delete ptr_; // memory leak emerges if this deletion is PRESENT
            ptr_ = nullptr;
//            cout << "destructor : nullified ptr_" << endl;
        }
    }

    void reset(Expression *ptr = nullptr) {
        if (ptr != nullptr) {
            ptr_ = ptr;
            *refCounter = 1;
        } else {
            safeDecRefCounter();
            safeDeleteRefCounterIfNeeded();
        }
    }

    SharedPtr &operator=(SharedPtr const &other) {
//        if (ptr_ == other.ptr_) { // is it correct check for assigning to itself ???
//            // todo continue here
//            cout << "ptr_ == other.ptr_" << endl;
//        }
        if (this != &other) // to avoid unnecessary operations if we have the same instance
        {
            if (ptr_ != nullptr) {
//                (*refCounter)--;
                safeDecRefCounter();
            }
            if (other.ptr_ != nullptr && other.refCounter != nullptr) {
//        if (other.ptr_ != nullptr && other.refCounter != nullptr && *(other.refCounter) > 0) {
                (*(other.refCounter))++;
            }
            // delete pointers before new assignment !!!
        }
        return *this;
    }

    /* method release() is absent in the task */
    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        ptr_ = nullptr;
        if (refCounter != nullptr)
            *refCounter = 0;
        return tmp;
    }

    // these methods don't require to be tested as they are simple getters and setters -------------

    Expression *get() const { return ptr_; }

    Expression &operator*() const { return *ptr_; }

    Expression *operator->() const { return ptr_; }

    bool operator==(double const *d) {
        if (ptr_ != nullptr) {
            Number n = ptr_->evaluate(); // receiving Expression but can instead use its child - Number
            return n.evaluate() == *d; // comparing real double values got from inside Number class
        } else return false;
    }

private:
    Expression *ptr_;
    int *refCounter = new int(0);

    /* counts only different pointers - how many separate instances we have */

    void safeDecRefCounter() {
        if (refCounter != nullptr && *refCounter > 0) {
            (*refCounter)--;
        }
    }

    void safeDeleteRefCounterIfNeeded() {
        if (refCounter != nullptr && *refCounter == 0)
            delete refCounter;
    }
};

#endif //_LEARNING_C_CPP_SHAREDPTR_HPP