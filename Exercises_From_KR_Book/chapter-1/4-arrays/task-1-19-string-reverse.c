// reverse for a string

#include <stdio.h>

#define MAX_LENGTH 100

int reverse() {
    int c, count = 0;
    char s[MAX_LENGTH];
    char r[MAX_LENGTH];
    for (int i = 0; i <= MAX_LENGTH; ++i)
        s[i] = 0;
    while ((c = getchar()) != EOF && c != '\n')
        s[count++] = (char) c;
    for (int i = 0; i <= MAX_LENGTH; ++i)
        r[i] = 0;
    for (int i = 0; i <= count; ++i)
        r[count - i] = s[i];
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