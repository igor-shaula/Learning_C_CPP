#include <stdio.h>

main()
{
    printf("from Fahrehheit to Celsius in reversed order:\n");

    for (int fd = 300; fd >= 0; fd -= 10)
    {
        printf("%3d\t%3.2f\n", fd, (5.0 / 9.0) * (fd - 32));
    }
}