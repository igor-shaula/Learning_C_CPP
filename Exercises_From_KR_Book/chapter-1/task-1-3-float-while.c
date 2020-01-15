#include <stdio.h>

/* translation of Celsius degrees to Fahrenheit degrees */

int main() {
    float cd; // Celsius degrees
    float fd; // fahrenheit degrees
    const int limit_low = -20;
    const int limit_hi = 300;
    const int step = 10;

    fd = limit_low;
    while (fd <= limit_hi) {
        cd = (5.0 / 9.0) * (fd - 32.0);
        printf("Celsius: %3.2f \t Fahrenheit: %3f \n", cd, fd);
        fd += step;
    }
    return 0;
}