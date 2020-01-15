#include <stdio.h>

int main() {
    int c = 0;

    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }
    return 0;
}