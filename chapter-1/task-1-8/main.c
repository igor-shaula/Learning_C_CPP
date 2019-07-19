#include <stdio.h>

main()
{
    int spaces = 0;
    int tabs = 0;
    int eols = 0;

    int c;
    while ((c = getchar()) != EOF)
    {
        // printf("\n");
        if (c == ' ')
        {
            spaces++;
        }
        else if (c == '\t')
        {
            tabs++;
        }
        else if (c == '\n')
        {
            eols++;
            printf("TOTAL spaces: %d, tabs: %d, lines: %d\n", spaces, tabs, eols);
        }
    }
}