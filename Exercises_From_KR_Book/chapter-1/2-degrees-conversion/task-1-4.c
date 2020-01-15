#include <stdio.h>

/* translation of Celsius degrees to Fahrenheit degrees */

int main() {
    float cd; // Celsius degrees
    float fd; // fahrenheit degrees
    const int limit_low = -100;
    const int limit_hi = 300;
    const int step = 10;

    printf("Celsius\t\tFahrenheit\n");

    cd = limit_low;
    while (cd <= limit_hi) {
        fd = cd * (9.0 / 5.0) + 32.0;
        printf("%3.0f\t\t\t\t\t%3.1f\n", cd, fd);
        cd += step;
    }
    return 0;
}