#include <malloc.h>
#include "ClassesInDynamicMemory.hpp"
#include "iostream"

using namespace std;

void println(size_t size, string const &comment) {
    cout << size << ':' << comment << endl;
}

int main() {

    /* allocation of memory and immediate creation of object in this allocated memory */
    auto *pia = new IntArray(9);
    println(pia->size(), "pia");

    /* only allocation of memory without any sort of initialization of this found memory */
    auto *pia1 = (IntArray *) (malloc(sizeof(IntArray)));
    println(pia1->size(), "pia1 via malloc()");
    pia1->~IntArray(); // explicitly calling destructor
    println(pia1->size(), "pia1 after destructor 1");
    pia1->~IntArray(); // we can safely invoke destructor & 'delete' more than one time ???
    println(pia1->size(), "pia1 after destructor 2");

//    IntArray *pia2 = new IntArray(); // a sample for comparison to the next line
    auto *pia2 = new IntArray; // yes, we can invoke method without brackets
    println(pia2->size(), "pia2");

    /* sample of using 'placement new' approach */
    const size_t count = 10;
    char *buffer = new char[count * sizeof(int)];
    int *ptr = (int *) buffer;
    for (size_t i = 0; i != count; ++i)
        new(ptr + i) int(i);
    delete[] buffer;

    /* allocating memory directly - has to give the same effect as the sample with placement new */
    int *ptrd = (int *) ::operator new[](count * sizeof(int));

    /* checking if it worked: */
    for (size_t i = 0; i < count; ++i) {
        println(ptr[i], "ptr"); // strange that ptr[1] is 0
        println(ptrd[i], "ptrd"); // strange that ptrd[1] is 0
    }

    void *p = malloc(sizeof(IntArray));
    auto *a = new(p) IntArray(10); // 'new' with placement - just invokes constructor for given address
    println(a->size(), " new(..)");
    a->~IntArray(); // destructor clears inner state of existed object
    println(a->size(), " new(..) after destructor");
    free(a);
    println(a->size(), " new(..) after free");

    /* if we create an array on stack (not in heap) - it will have problems with alignment */
    char b[sizeof(IntArray)]; // memory is allocated ON STACK
    new(b) IntArray(5); // initializing allocated memory by calling constructor
    /* i suppose that for the last sample no deletion is needed as objects on stack are cleaned automatically */

    struct A {
        A(int x) {} // note that we have no default constructor here
        ~A() {}
    };

    const int n = 50;
    /*! actual allocation goes here */
    A *placementMemory = static_cast<A *>(operator new[](n * sizeof(A)));
    //! that's it - now when we have allocated memory - we can write something there
    for (int i = 0; i < n; i++) {
        new(placementMemory + i) A(rand()); //здесь память для объекта не выделяется, но инициализируется
    }
    //! деинициализация памяти - green text begins after ! in comment
    for (int i = 0; i < n; i++) {
        placementMemory[i].~A();
    }
    operator delete[](placementMemory);

    return 0;
}