#include <stdio.h>

/* translation of Celsius degrees to Fahrenheit degrees */

int main() {
    int cd; // Celsius degrees
    int fd; // fahrenheit degrees
    int limit_low = -20;
    int limit_hi = 300;
    int step = 10;

    fd = limit_low;
    for (int i = limit_low; i <= limit_hi; i += step) {
        // cd = (5 / 9) * (fd - 32);
        cd = 5 * (fd - 32) / 9;
        printf("Celsius: %3d \t Fahrenheit: %3d \n", cd, fd);
        fd += step;
    }
    return 0;
}