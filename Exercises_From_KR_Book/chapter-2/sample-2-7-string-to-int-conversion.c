// analog of atoi() - simplest conversion from given string to its numeric value

#include<stdio.h>

int simple_atoi(char s[]) {
    int i, n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main() {
    printf("%d\n", simple_atoi("40") + 2);
    return 0;
}