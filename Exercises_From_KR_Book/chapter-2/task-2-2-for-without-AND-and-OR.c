// another version of getLine() function but without && and || operators

#include <stdio.h>

#define MAX_LENGTH 10

int getLine() {
    int i, c;
    char s[MAX_LENGTH];
    for (i = 0; i < MAX_LENGTH; ++i)
        s[i] = 0;
    printf("getLine - all ready:\n");
    for (i = 0; i < MAX_LENGTH - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    printf("%s\n", s);
}

int getLineAlternative() {
    int i, c;
    char s[MAX_LENGTH];
    for (i = 0; i < MAX_LENGTH; ++i)
        s[i] = 0;
    printf("getLineAlternative - all ready:\n");
    for (i = 0; (i < MAX_LENGTH - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i)
        s[i] = c;
    printf("%s\n", s);
}

//int test() {
//    return (1 == 2) * (1 == 1);
//}

int main() {
    getLine();
    getLineAlternative();
//    printf("%d\n", test());
    return 0;
}