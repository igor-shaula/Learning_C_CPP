// creates histogram with length of all words from input:

#include<stdio.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20 // possible number of characters in a word

int main() {

    // preparation:
    int c;
    bool insideWordFlag;
    char currentWordLength = 0; // 255 definitely is enough
    int allWordsLength[MAX_WORD_LENGTH];
    for (char i = 0; i < MAX_WORD_LENGTH; ++i)
        allWordsLength[i] = 0;
    // processing input:
    while ((c = getchar()) != '\n') {
        // detecting words:
        insideWordFlag = (c != ' ' && c != '\t');
        // processing words:
        if (insideWordFlag) {
            ++currentWordLength;
        } else {
            allWordsLength[currentWordLength]++; // all words with 4 characters have index 4 here
            currentWordLength = 0;
        }
    }
    // fixing possibly wrong state with uncounted last word:
    allWordsLength[currentWordLength]++;
    // outputting results:
    printf("first row shows quantity of characters in words and second - how often they occur:\n");
    for (char i = 0; i < MAX_WORD_LENGTH; ++i)
        printf("%d\t", i);
    printf("\n");
    for (char i = 0; i < MAX_WORD_LENGTH; ++i)
        printf("%d\t", allWordsLength[i]);
    return 0;
}