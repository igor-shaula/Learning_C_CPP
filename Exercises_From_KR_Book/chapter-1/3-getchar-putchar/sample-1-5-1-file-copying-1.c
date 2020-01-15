// copying from input stream to output stream

#include <stdio.h>
int main() {
    int c;
    // type `int` is chosen instead of `char` for having ability to use EOF which is greater than `char`
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
        // special case for having ability to exit from program normally:
        if (c == 'c')
            return 0;
    }
    return 0;
}