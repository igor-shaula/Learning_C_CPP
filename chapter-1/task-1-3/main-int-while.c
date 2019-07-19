#include <stdio.h>

/* translation of Celsius degrees to Fahrenheit degrees */

main()
{
    int cd; // Celsius degrees
    int fd; // fahrenheit degrees
    const int limit_low = -20;
    const int limit_hi = 300;
    const int step = 10;

    fd = limit_low;
    while (fd <= limit_hi)
    {
        // cd = (5 / 9) * (fd - 32);
        cd = 5 * (fd - 32) / 9;
        printf("Celsius: %3d \t Fahrenheit: %3d \n", cd, fd);
        fd += step;
    }
}