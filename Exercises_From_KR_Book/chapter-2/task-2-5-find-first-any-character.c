// finds first occurrence of s2 inside s1

#include <stdio.h>

int findAny(const char s1[], const char s2[]) {
    int i1, i2;
    i1 = 0;
    while (s1[i1] != '\0') {
        printf("s1[i1]: %c\n", s1[i1]);
        i2 = 0;
        while (s2[i2] != '\0') {
            printf("s2[i2]: %c\t", s2[i2]);
            if (s1[i1] == s2[i2])
                return i1;
            putchar('\n');
            ++i2;
        }
        putchar('\n');
        ++i1;
    }
    return -1;
}

int main() {
    char s1[] = "1234567890";
    char s2[] = "89";
    printf("\nfound position: %i\n", findAny(s1, s2));
    return 0;
}