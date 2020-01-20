// reverse for a string

#include <stdio.h>

#define MAX_LENGTH 100

int reverse() {
    int c, count = 0;
    char s[MAX_LENGTH];
    char r[MAX_LENGTH];
    // preparation of source array:
    for (int i = 0; i <= MAX_LENGTH; ++i)
        s[i] = 0;
    // filling first array from input:
    while ((c = getchar()) != EOF && c != '\n')
        s[count++] = (char) c;
    // preparation of reversed array:
    for (int i = count + 1; i <= MAX_LENGTH; ++i) // elements up to `count` would be anyway rewritten
        r[i] = 0;
    // copying from initial array in reverse order:
    for (int i = 0; i <= count; ++i)
        r[count - i] = s[i];
    // outputting - here we need this loop as formatted print does not work with incorrect strings
    for (int i = 0; i <= count; ++i)
        printf("%c", r[i]);
    printf("\n");
//    printf("%s\n", r); // for some reason outputs empty line instead of existing string
    return count;
}

int main() {
    while (reverse() > 0);
    return 0;
}