#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        printf(c);
    }
    if (c == EOF)
    {
        printf("1"); // in theory this has to be the last thing to see in output
    }
    else
    {
        printf("not equals EOF"); // we shouldn't ever see that
    }
}