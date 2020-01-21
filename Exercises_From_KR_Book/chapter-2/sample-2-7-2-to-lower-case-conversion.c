// simplest conversion of anything to lower case

#include <stdio.h>

// works correctly only with characters from ASCII table
int toLowerCaseASCII(int const c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

#include <ctype.h> // contains useful functions to work with different standard types
int main() {
    printf("%c\n", toLowerCaseASCII('Q'));
    printf("%d\n", isdigit('Q'));
    printf("%d\n", islower('Q'));
    printf("%c\n", tolower('Q'));
    return 0;
}