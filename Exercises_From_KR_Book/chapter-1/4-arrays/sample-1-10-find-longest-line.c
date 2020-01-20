// find and prints longest line of chars from input

#include <stdio.h>

#define MAX_LENGTH 100

// new here - global variables and use of them:
int max;
char line[MAX_LENGTH];
char longest[MAX_LENGTH];

// it's better to intentionally write `void` in function's parameters list
int getLine(void);
void copy(void);

int main() {
    int length;
    extern int max; // linking global variable possibly from another file in this way
    extern char longest[]; // no need to specify array size again
    max = 0;
    while ((length = getLine()) > 0)
        if (length > max) {
            max = length;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getLine(void) {
    int c, i;
    extern char line[];
//    for (i = 0; i < MAX_LENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i) // endless input...
    for (i = 0; i < MAX_LENGTH - 1 && (c = getchar()) != EOF && c != '\n' && c != '~'; ++i)
//  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n' && c != '~'; ++i) // ~ is really needed
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy() {
    int i = 0;
    extern char line[], longest[];
    while ((longest[i] = line[i]) != '\0')
        ++i;
}