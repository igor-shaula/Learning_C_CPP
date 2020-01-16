// counting spaces, tabulations and ends of lines

#include <stdio.h>

int main() {
    int spaces = 0;
    int tabs = 0;
    int eols = 0;
    int c;
    while ((c = getchar()) != EOF) {
        // 1-printf("\n");
        if (c == ' ')
            spaces++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n') {
            eols++;
            printf("TOTAL spaces: %d, tabs: %d, lines: %d\n", spaces, tabs, eols);
        }
    }
    return 0;
}