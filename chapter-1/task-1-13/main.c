#include<stdio.h>

main() {

    int c;
    // int word_lengths[];
    int inside_word = 0;
    int letter_counter = 0;
    int word_counter = 0;

    while ((c = getchar()) != '\n')
    {
        if (c == ' ' || c == '\t')
        {
            inside_word = 0;
        }
        else
        {
            inside_word = 1;
        }
        
        if(inside_word == 1) {
            letter_counter++;
        } else {
            word_counter++;
        }

        // word_lengths = new array ...
    }
    printf("words totally: %d", word_counter);
}