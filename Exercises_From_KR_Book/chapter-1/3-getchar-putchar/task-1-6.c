// checking real value of EOF

#include <stdio.h>

int main() {
    int c;
    if ((getchar() != EOF) == 1)
        printf("!= EOF -> 1");
    else if ((getchar() != EOF) == 0)
        printf("!= EOF -> 0");
    else
        printf("something else - not 1 or 0");
    return 0;
}