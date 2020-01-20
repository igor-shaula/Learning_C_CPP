// removes excess tabs and spaces in the line endings and also removes empty lines

#include <stdio.h>

#define MAX_LENGTH 100

// detecting either we're in the line's ending or need to copy all anyway
char spaceOrTab(const char c) {
    return c == ' ' || c == '\t';
}

char valueFound(const char c) {
    return c != 0 && (spaceOrTab(c) ? 0 : 1);
}

int processLine() {
    int c, count = 0;
    char s[MAX_LENGTH]; // string from input
    char p[MAX_LENGTH]; // to be printed
    // initializing both arrays:
    for (int i = 0; i < MAX_LENGTH; ++i)
        s[i] = p[i] = 0;
    // filling first array from input:
    while ((c = getchar()) != EOF && c != '\n')
        s[count++] = (char) c; // first write to array, than increment

    char needToCopyAll = valueFound(s[count]);
    // removing unwanted characters - from end to beginning:
    for (int i = count; i >= 0; --i) { // `count` now has needed value
        if (!needToCopyAll) { // skip spaces
            needToCopyAll = valueFound(s[i]);
            if (needToCopyAll) p[i] = s[i]; // this should heal absence of last character
        } else // just copy
            p[i] = s[i];
    }
    printf("%s\n", p);

    return count;
}

int main() {
    while (processLine() != 0);
    return 0;
}