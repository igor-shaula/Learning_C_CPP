// removes certain characters from given string

#include <stdio.h>

#define MAX_LENGTH 100

char t[MAX_LENGTH];

int getLength(const char a[]) {
    int length = 0;
    while (a[length++] != '\0');
    printf("length is: %d\n", length);
    return length;
}

void squeezeFromBook(char s[], char c) { // it's `void` in the book
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            t[j++] = s[i]; // segmentation fault here
    t[j] = '\0';
}

void squeeze(char s[], char c) { // it's `void` in the book
    // realisation differs from given by book in using second/global array for result
    int i, shift = 0;
    char tmpChar;
    for (i = 0; (tmpChar = s[i]) != '\0'; i++) {
        if (tmpChar == c) // need to skip this character and write later in place of it
            ++shift;
        else
            t[i - shift] = tmpChar; // if using initial array - interrupted by signal 11: SIGSEGV
    }
    t[i - shift] = '\0';
}

void fillArray(char a[]) {
    if (a == 0) return;
    while (*a != '0') *a = '0';
}

int main() {
    fillArray(t);
//    squeezeFromBook("asdf", 's');
    squeeze("asdf", 's');
    printf("%s\n", t);
    return 0;
}