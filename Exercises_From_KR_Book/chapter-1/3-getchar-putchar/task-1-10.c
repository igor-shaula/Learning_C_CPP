// copying from input stream to output while replacing tabs, backspaces and backslashes with '\'

#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') { // how to detect this symbol ???
            putchar('\\');
            putchar('b');
        } else if (c == '\\')
            putchar('\\');
        putchar(c);
    }
    return 0;
}