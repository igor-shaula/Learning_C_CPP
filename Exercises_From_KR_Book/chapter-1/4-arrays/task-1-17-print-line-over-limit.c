// outputs all strings longer than given limit in output stream

#include <stdio.h>

#define LIMIT 10 // 80 in task but it's too long for testing
#define MAX_LENGTH 100

void printLine(char line[]) {
    printf("%s\n", line);
}

int getLine() {
    // prepare all needed variables:
    int c, count = 0;
    char s[MAX_LENGTH];
    // read input and store it:
    while ((c = getchar()) != EOF && c != '\n') {
        s[count] = (char) c;
        ++count;
    }
    // print if needed:
    if (count > LIMIT)
        printLine(s);
    return count;
}

int main() {
    while (getLine() != 0);
    return 0;
}