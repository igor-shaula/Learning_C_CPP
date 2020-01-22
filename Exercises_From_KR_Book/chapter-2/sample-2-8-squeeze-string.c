// removes certain characters from given string

#include <stdio.h>

char *squeezeFromBook(char s[], char c) { // it's `void` in the book
    // realisation the same as in the book - but for some reason it does not work
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i]; // segmentation fault here
    s[j] = '\0';
    return s;
}

char *squeeze(char s[], char c) { // it's `void` in the book
    // realisation the same as in the book - but for some reason it does not work
    int i, shift;
    char tmpChar;
    int length = 0;
    while (s[length++] != '\0');
    printf("length is: %d\n", length);
    char t[length];
    for (i = 0; (tmpChar = s[i]) != '\0'; i++) {
        putchar(tmpChar);
        if (s[i] == c) // need to skip this character and write later in place of it
            ++shift;
        else
//            s[i - shift] = tmpChar;
            t[i - shift] = tmpChar; // interrupted by signal 11: SIGSEGV
        // it seems that there is no difference between concrete array that we're using
    }
    t[i - shift] = '\0';
    return t;
}

int main() {
    char *p = squeeze("asdf", 's');
    printf("%s\n", p);
    return 0;
}