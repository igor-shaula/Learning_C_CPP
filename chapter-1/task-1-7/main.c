#include <stdio.h>

main()
{
    int eof = putchar(EOF);
    printf("\nEOF int value is: %d", eof); // gives 255 for some reason
    // printf("EOF int value is: %d", -1); // should be -1
}