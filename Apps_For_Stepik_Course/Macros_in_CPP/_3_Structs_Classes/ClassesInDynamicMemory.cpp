#include <malloc.h>
#include "ClassesInDynamicMemory.hpp"
#include "iostream"

using namespace std;

void println(size_t size, string const &comment) {
    cout << size << ':' << comment << endl;
}

int main() {

    /* allocation of memory and immediate creation of object in this allocated memory */
    IntArray *pia = new IntArray(9);
    println(pia->size(), "pia");

    /* only allocation of memory without any sort of initialization of this found memory */
    IntArray *pia1 = (IntArray *) (malloc(sizeof(IntArray)));
    println(pia1->size(), "pia1 via malloc()");
    pia1->~IntArray(); // explicitly calling destructor
    println(pia1->size(), "pia1 after destructor 1");
    pia1->~IntArray(); // we can safely invoke destructor & 'delete' more than one time ???
    println(pia1->size(), "pia1 after destructor 2");

//    IntArray *pia2 = new IntArray(); // a sample for comparison to the next line
    IntArray *pia2 = new IntArray; // yes, we can invoke method without brackets
    println(pia2->size(), "pia2");

    /* sample of using 'placement new' approach */
    const size_t count = 10;
    char *buffer = new char[count * sizeof(int)];
    int *ptr = (int *) buffer;
    for (size_t i = 0; i != count; ++i)
        new(ptr + i) int(i);
    delete[] buffer;

    /* checking if it worked: */
    for (size_t i = 0; i < count; ++i)
        println(ptr[i], "");

    return 0;
}