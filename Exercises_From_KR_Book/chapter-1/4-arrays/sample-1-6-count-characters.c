// counting digits, spaces and other symbols

#include <stdio.h>

void countFromInput() {
    // declaration:
    int c, i, nSpace, nOther, nDigits[10];
    // initialization:
    nSpace = nOther = 0;
    for (i = 0; i < 10; ++i)
        nDigits[i] = 0;
    // payload:
    while ((c = getchar()) != EOF && c != 'c') { // 'c' added fro ability to exit normally
        if (c >= '0' && c <= '9')
            ++nDigits[c - '0']; // two brilliant solutions are used here
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nSpace;
        else
            ++nOther;
    }
    // output:
    printf("digits:");
    for (i = 0; i < 10; ++i)
        printf(" %d", nDigits[i]);
    printf(", spaces: %d, others: %d\n", nSpace, nOther);
}

int main() {
    countFromInput();
    return 0;
}