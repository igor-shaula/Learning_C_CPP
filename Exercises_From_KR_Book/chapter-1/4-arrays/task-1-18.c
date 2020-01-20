// removes excess tabs and spaces in the line endings and also removes empty lines

#include <stdio.h>

#define MAX_LENGTH 100

// detecting either we're in the line's ending or need to copy all anyway
char wantedCharacter(const char c) {
    return c != ' ' && c != '\t';
}

int processLine() {
    int c, count = 0;
    char s[MAX_LENGTH]; // string from input
    char p[MAX_LENGTH]; // to be printed
    // initializing both arrays:
    for (int i = 0; i < MAX_LENGTH; ++i) {
        s[i] = 0;
        p[i] = 0;
    }
    // filling first array from input:
    while ((c = getchar()) != EOF && c != '\n')
        s[count++] = (char) c; // first write to array, than increment
    char potentialEndSpaces = 1;
    // removing unwanted characters - from end to beginning:
    for (int i = count; i >= 0; --i) { // `count` now has needed value
//        potentialEndSpaces = wantedCharacter(s[i]); // how to reverse function's returning value here?
        if (wantedCharacter(s[i]) && !potentialEndSpaces)
            p[i] = s[i];
        else {
            potentialEndSpaces = 0;
        }
    }
    printf("%s\n", p);

    return count;
}

int main() {
    while (processLine() != 0);
    return 0;
}