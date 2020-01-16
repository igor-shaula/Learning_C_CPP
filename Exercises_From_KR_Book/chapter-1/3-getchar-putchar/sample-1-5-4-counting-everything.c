// counting of lines, words and symbols inside input stream

#include <stdio.h>

#define IN 1
#define OUT 0

void countEverything() {
    int c, nLines, nWords, nSymbols, state;
    state = OUT;
    nLines = nWords = nSymbols = 0;
    while ((c = getchar() != EOF)) {
        ++nSymbols;
        if (c == '\n' || c == ' ' || c == '\t') {
            state = OUT;
            if (c == '\n')
                ++nLines;
        } else if (state == OUT) {
            ++nWords;
            state = IN;
        }
    }
    printf("lines:%d ,words%d ,symbols%d\n", nLines, nWords, nSymbols);
}

int main() {
    countEverything();
    return 0;
}