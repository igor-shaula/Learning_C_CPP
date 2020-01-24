// adds new string to the end of existing one - there must be enough space in existing string

#include <stdio.h>

void strConcat(char s[], char t[]) { // `strcat` in book
    int i, j;
    i = j = 0;
    // firstly we have to find the end of existing string:
    while (s[i] != '\0')
        ++i; // now `i` contains index of ending zero - from this place we have to start copying
    while ((s[i++] = t[j++]) != '\0'); // copy first, increment later
}

int main() {
    char s[] = "asdf";
    char t[] = "zxcv";
    strConcat(s, t);
    printf("%s", s);
    return 0;
}