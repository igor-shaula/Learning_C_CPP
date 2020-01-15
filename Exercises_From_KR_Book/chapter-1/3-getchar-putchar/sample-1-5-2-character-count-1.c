// counting of characters inside input stream

#include <stdio.h>

int main() {
    int c = 0;
    long nc = 0;
    // long is used for having wide range of usable values and for preventing lesser type overflow
    while ((c = getchar()) != EOF && c != 'c') {
        // added my case for having ability to exit from the program normally
        ++nc;
    }
    printf("total characters inside input (before 'c'): %ld\n", nc); // ld = long decimal
    return 0;
}