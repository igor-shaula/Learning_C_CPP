// simplest line counting ever

#include <stdio.h>

int main() {
    int c, lines = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++lines;
        else if (c == 'c') {
            lines += 1; // for compensating the line which contains this 'c' symbol
            break;
        }
    }
    printf("lines before EOF: %d\n", lines);
    return 0;
}