// conversion from HEX values in string form to decimal `int` values

#include <stdio.h>
#include <ctype.h>

int isNumber(const char c) {
    return c >= '0' && c <= '9';
}

int isHexNumber(const char c) {
    return isNumber(c) || (tolower(c) >= 'a' && tolower(c) <= 'f');
}

int isHexPrefix(const char c0, const char cx) {
    return c0 == '0' && tolower(cx) == 'x';
}

int convertHtoI(char s[]) {
    int value = 0;
    // get length of given array:
    int length = 0;
    while (s[length] != '\0') ++length; // does not count closing zero
    printf("string length is: %d\n", length);
    if (length <= 2 || (s[0] == '-' && length <= 3)) {
        printf("not enough length for HEX->INT conversion\n");
        return 0;
    }
    // special flag for interpreting ABCDEF like numbers if they are preceded by 'x' or 'X'
    char flag = 0;
    // loop through given string and process each character:
    for (int i = 0, c = 0; i < length; ++i) {
        printf("%c\n", s[i]);
        if (flag) {
            // process HEX format correctly
            if (isHexNumber(c))
                value = 16 * value + c - 'a' + 10;
            else putchar('_');
        } else {
            // process decimal numbers
            if (isNumber(c) && (i + 1) < length && tolower(s[i + 1]) != 'x')
                value = 10 * value + s[i] - '0'; // simple conversion

            else if (i + 1 < length && tolower(s[i + 1]) == 'x')
                flag = 1;

        }

        putchar(s[i]);
        putchar('\n');
    }
    return value;
}

int main() {
    printf("result of conversion is: %d\n", convertHtoI("0xa1"));
    return 0;
}