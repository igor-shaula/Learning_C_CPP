// showing histogram of each character frequency of occurrence (from input)

#include <stdio.h>

#define MAX_CHAR_VALUE 255

int main() {
    int c = 0;
    int results[MAX_CHAR_VALUE];
    for (int i = 0; i < MAX_CHAR_VALUE; ++i)
        results[i] = 0;
    while ((c = getchar()) != '\n') {
        results[c]++;
    }
    for (int i = 0; i < MAX_CHAR_VALUE; ++i)
        if (i == '\n') printf("!n");
        else if (i == '\t') printf("!t");
        else if (i == ' ') printf("!s"); // here shifting appears in output rows
        else printf("%c ", i);
    printf("\n");
    for (int i = 0; i < MAX_CHAR_VALUE; ++i)
        printf("%d ", results[i]);
    return 0;
}