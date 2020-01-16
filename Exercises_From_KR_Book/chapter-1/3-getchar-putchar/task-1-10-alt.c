// alternative copying from input stream to output while replacing tabs, backspaces and backslashes with '\'

#include <stdio.h>

int main() {
    int c;
    short needToDeleteSpace;
    while ((c = getchar()) != EOF) {
        needToDeleteSpace = 0;
        if (c == '\t') {
            putchar('\\');
            putchar('t');
            needToDeleteSpace++;
        } else if (c == '\b') { // how to detect this symbol ???
            putchar('\\');
            putchar('b');
        } else if (c == '\\')
            putchar('\\');
        if (needToDeleteSpace == 0)
            putchar(c);
    }
    return 0;
}