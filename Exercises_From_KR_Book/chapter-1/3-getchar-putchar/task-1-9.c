// copying from input stream to output while replacing of multiple spaces with one

#include <stdio.h>

int main() {
    int c;
    int space_counter = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_counter++;
            if (space_counter > 1) {
                // c = '\b';
                putchar('\b');
                space_counter = 1;
            }
        } else
            space_counter = 0;
        putchar(c);
    }
    return 0;
}