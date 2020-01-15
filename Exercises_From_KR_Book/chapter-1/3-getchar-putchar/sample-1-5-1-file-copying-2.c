// optimized version of copying file from input to output - shorter form than in version 1

#include<stdio.h>

int main() {
    int c;
    // we know that function inside brackets will be the first to be called - and that's why:
    while ((c = getchar()) != EOF && c != 'c') // it's possible to use `c` variable right here
        putchar(c);
    return 0;
}