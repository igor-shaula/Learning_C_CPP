#include <stdio.h>
#include <stdlib.h>

//#define LENGTH 4

struct Node {
    char value;
    struct Node *nextNodePtr;
} node;

void reverse(struct Node *ptr) {
    // say we have only pointer to starting element:
}

struct Node *getNext(struct Node n) {
    return n.nextNodePtr;
}

int main() {

    printf("\ninput numbers for one-way-list here (must end with '\\n'): ");
    int c, length = 0;
    struct Node *currentNode = (struct Node *) malloc(sizeof(node));
    while ((c = getchar()) != '\n') {
        currentNode->value = c;
        struct Node *nextNode = (struct Node *) malloc(sizeof(node));
        currentNode->nextNodePtr = nextNode;
        ++length;
    }
    // preparing last closing node:
    struct Node *lastNode = (struct Node *) malloc(sizeof(node));
    lastNode->value = '\n';
    lastNode->nextNodePtr = 0;

    // array of nodes is meant for use in reverse
    struct Node *ptrArray[length + 1];
    for (int i = 0; i < length - 1; ++i)
        ptrArray[i]->nextNodePtr = ptrArray[i + 1];
    ptrArray[length - 1] = lastNode;
    ++length;

    // printing initial array:
    for (int i = 0; i < length; ++i)
        putchar(ptrArray[i]->value);
//        putchar(ptrArray[i]->value);

    // reversing links between nodes:
    for (int i = length - 1; i > 0; --i) {
        ptrArray[i]->nextNodePtr = ptrArray[i - 1];
    }

//    struct Node *ptrArray[LENGTH];
    // initialization of everything:
//    i = 0;
//    for (i = 0; i < LENGTH; ++i) {
//        ptrArray[i] = (struct Node *) malloc(sizeof(node));
//        ptrArray[i]->value = 0;
//    }
//    ptrArray[LENGTH - 1]->nextNodePtr = 0;
//    for (i = LENGTH - 2; i > 0; --i)
//        ptrArray[i]->nextNodePtr = ptrArray[i];

    // detecting real size of array:
//    int length = 0;
//    while (ptrArray[length++]->value < LENGTH);
//    while (ptrArray[length++]->nextNodePtr != 0);
    printf("length is: %d", length);
//    printf("length is: %d", ptrArray[length]->nextNodePtr);

//    ptrArray[0] = 0;

    // clearing memory:
    for (int i = 0; i < length; ++i)
        free(ptrArray[i]);
    return 0;
}