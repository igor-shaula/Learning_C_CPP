#include <stdio.h>

#define LIMIT_HI 300
#define LIMIT_LOW 0
#define STEP 10

main()
{
    printf("from Fahrehheit to Celsius in reversed order:\n");

    for (int fd = LIMIT_HI; fd >= LIMIT_LOW; fd -= STEP)
    {
        printf("%3d\t%3.2f\n", fd, (5.0 / 9.0) * (fd - 32));
    }
}