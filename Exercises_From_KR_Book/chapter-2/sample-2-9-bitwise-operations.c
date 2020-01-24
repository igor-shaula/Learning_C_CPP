// samples of using bit operations

#include <stdio.h>
#include <values.h>

int main() {
    int decimal = 42;
    int octal = 052;
    int hex = 0x2a;
    printf("%d %d %d\n", decimal, octal, hex);

    unsigned int twoBytes = USHRT_MAX;
    printf("%d\n", twoBytes); // initial 16 bits of ones
    printf("%d\n", twoBytes & 0xffu); // & = multiplied by 8 bits of ones - first 8 bits -> 0
    printf("%d\n", twoBytes & 010u); // every bit except pre-pre-last one becomes 0

    printf("%d\n", twoBytes | 01u); // complemented last 4 bits to be all ones
}