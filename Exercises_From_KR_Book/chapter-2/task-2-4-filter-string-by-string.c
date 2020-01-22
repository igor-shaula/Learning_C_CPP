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

void squeeze(const char s1[], const char s2[]) { // it's `void` in the book
    // realisation differs from given by book in using second/global array for result
    int i, j, shift = 0;
    char tmpChar1, tmpChar2;
    for (i = 0; (tmpChar1 = s1[i]) != '\0'; i++) {
        for (j = 0; (tmpChar2 = s2[j]) != '\0'; j++) {
            if (tmpChar1 == tmpChar2) // need to skip this character and write later in place of it
                ++shift;
            else
                t[i - shift] = tmpChar1; // if using initial array - interrupted by signal 11: SIGSEGV
        }
    }
    t[i - shift] = '\0';
}

void fillArray(char a[]) {
    if (a == 0) return;
    while (*a != '0') *a = '0';
}

int main() {
    fillArray(t);
    squeeze("12345", "3");
    printf("%s\n", t);
    return 0;
}