// simplest conversion of anything to lower case

#include <stdio.h>

int toLowerCase(int const c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main() {
    printf("%c\n", toLowerCase('Q'));
    return 0;
}