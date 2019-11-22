#ifndef _LEARNING_C_CPP_SHAREDPTR_HPP
#define _LEARNING_C_CPP_SHAREDPTR_HPP

#include <iostream>
#include "Expression.hpp"


using namespace std;

struct SharedPtr {
    explicit SharedPtr(Expression *ptr = nullptr) {
//    explicit SharedPtr(Expression *ptr) {
//        cout << "constructor : counter was: " << counter << endl;
        if (ptr != nullptr) {
            refCounter = 1;
            if (ptr != ptr_) { // this is questionable
                ptr_ = ptr;
                ptrCounter++; // only counting different objects in memory
            }
//            cout << "constructor : counter is: " << counter << endl;
        }
    }

    SharedPtr(SharedPtr const &other) {
        if (other.ptr_ != nullptr) {
            refCounter++;  // this has to be the only place of this counter incrementation
            ptrCounter = other.ptrCounter;
            ptr_ = other.ptr_;
        }
    }

    ~SharedPtr() {
        refCounter--;
//        cout << "destructor : counter is: " << counter << endl;
        if (refCounter <= 0) {
            delete ptr_; // memory leak emerges if this deletion is absent
            ptr_ = nullptr;
            ptrCounter = 0;
//            cout << "destructor : nullified ptr_" << endl;
        }
    }

    SharedPtr &operator=(SharedPtr const &other) {
        if (this->ptr_ != nullptr)
            (this->refCounter)--;
        else {
        }
        // if (other.ptr_ != 0)
        // (other.refCounter)++;
        // todo - continue here
    }

    /* method release() is absent in the task */
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

//    int getCounter() const { return counter; }
//
//    int &setCounter() { return counter; }

private:
    Expression *ptr_;
    int ptrCounter = 0;
    int refCounter = 0;  // depends only on quantity of different pointers - in fact how many real instances we really have
};


#endif //_LEARNING_C_CPP_SHAREDPTR_HPP