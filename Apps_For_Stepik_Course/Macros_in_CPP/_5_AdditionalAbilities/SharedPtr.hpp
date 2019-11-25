#ifndef _LEARNING_C_CPP_SHAREDPTR_HPP
#define _LEARNING_C_CPP_SHAREDPTR_HPP

#include <iostream>
#include "Expression.hpp"

using namespace std;

struct SharedPtr {
    /* SharedPtr with nullptr inside cannot be created intentionally */

    explicit SharedPtr(Expression *ptr = nullptr) { // creates different objects
        if (ptr != nullptr) {
            ptr_ = ptr;
            safeSetRefCounterTo1();
        } // else - do nothing - we should not create wrappers around nullptr
    }

    SharedPtr(SharedPtr const &other) { // creates COPIES
        if (other.ptr_ != nullptr) {
            ptr_ = other.ptr_;
            safeIncreaseRefCounter();
        } // else - do nothing - we should not create wrappers around nullptr
    }

/* here we can have several different scenarios:
 * 1 - other is valid different SharedPtr with different pointer inside
 * 2 - other is valid different SharedPtr with the same pointer inside
 * 3 - other is valid the same SharedPtr with consequently the same pointer inside
 * 4 - other is invalid object - nullptr
 */
    SharedPtr &operator=(SharedPtr const &other) {
        if (this != &other) // to avoid unnecessary operations if we have the same instance
        {
            if (ptr_ != nullptr) {
                safeDecreaseRefCounter();
            }
            if (other.ptr_ != nullptr && other.refCounter != nullptr) {
                (*(other.refCounter))++;
            }
            // delete pointers before new assignment !!!
        }
        return *this;
    }

    void reset(Expression *ptr = nullptr) {
        if (ptr != nullptr) {
            ptr_ = ptr;
            safeSetRefCounterTo1();
        } else {
            safeDecreaseRefCounter();
            nullifyPtrIfNeeded();
            safeDeleteRefCounterIfNeeded();
        }
    }

    ~SharedPtr() {
        safeDecreaseRefCounter();
        nullifyPtrIfNeeded();
        safeDeleteRefCounterIfNeeded();
    }

    /* method release() is absent in the task */
/*
    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        ptr_ = nullptr;
        if (refCounter != nullptr)
            *refCounter = 0;
        return tmp;
    }
*/

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
    // counts only different pointers - how many separate instances we have

    void safeSetRefCounterTo1() {
        if (refCounter != nullptr) *refCounter = 1;
    }

    void safeIncreaseRefCounter() {
        if (refCounter != nullptr) (*refCounter)++;
    }

    void safeDecreaseRefCounter() {
        if (refCounter != nullptr && *refCounter > 0) (*refCounter)--;
    }

    void nullifyPtrIfNeeded() {
        if (refCounter == nullptr || *refCounter == 0) {
            ptr_ = nullptr; // delete ptr_; - memory leak emerges if this deletion is PRESENT
        }
    }

    void safeDeleteRefCounterIfNeeded() {
        if (refCounter != nullptr && *refCounter == 0) delete refCounter;
    }
};

#endif //_LEARNING_C_CPP_SHAREDPTR_HPP