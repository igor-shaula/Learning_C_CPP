// alternative version of counting of characters inside input stream

#include <stdio.h>

int main() {
    int c = 0;
    double nc;
    // `double` is used to widen available values range to even more than `long` can provide
    for (nc = 0; (c = getchar()) != EOF && c != 'c'; ++nc); // in spite of warning -it works OK
    // added my case for having ability to exit from the program normally
    printf("total characters inside input (before 'c'): %.0f\n", nc); // 0 symbols after `.`
    // note that this program has to work correctly even on input of zero length
    return 0;
}