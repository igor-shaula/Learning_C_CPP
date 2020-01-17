// this program finds and outputs the longest line in given data stream

#include <stdio.h>
#define MAX_LENGTH 10

//int getLine(char s[], const int limit);
int getLine(char s[]);
void copy(char to[], const char from[]);

int main() {
    int currentLength;
    int currentMax = 0;
    char currentLine[MAX_LENGTH];
    char longestLine[MAX_LENGTH];
    // basically this loop could be sent into another function but it would require work with pointers
    while ((currentLength = getLine(currentLine)) > 0)
        if (currentLength > currentMax) {
            currentMax = currentLength;
            copy(longestLine, currentLine);
        }
    if (currentMax > 0)
        printf("%s", longestLine); // s - for string output
    return 0;
}

// reads a string and return its length
int getLine(char s[]) {
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n' && c != '~'; ++i) // ~ is really needed
        s[i] = c;
    // here increment will happen after loop body is done
    if (c == '\n') {
        s[i] = c; // symbol of starting new line is also counted
        ++i; // we'll need this incremented value to anyway write ending zero
    }
    if (i > MAX_LENGTH) // as we're restricted in available line length - we have to do this
        s[MAX_LENGTH - 1] = '\0'; // forcibly making our string to be correct
    else
        s[i] = '\0'; // every correct C-style string must end with zero value
    return i;
}

// here length of destination array is considered to be enough to keep all values from source array
void copy(char to[], const char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
        // this check is added to prevent from endless copying from possibly incorrect string
        if (i >= MAX_LENGTH)
            break;
    }
}