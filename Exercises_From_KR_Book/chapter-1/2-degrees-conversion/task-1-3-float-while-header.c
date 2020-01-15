#include <stdio.h>

/* translation of Fahrenheit degrees to Celsius degrees */

int main() {
    float cd; // Celsius degrees
    float fd; // fahrenheit degrees
    const int limit_low = -20;
    const int limit_hi = 300;
    const int step = 10;

    printf("Fahrenheit\tCelsius\n");

    fd = limit_low;
    while (fd <= limit_hi) {
        cd = (5.0 / 9.0) * (fd - 32.0);
        printf("%3.0f\t\t\t\t\t%3.2f\n", fd, cd);
        fd += step;
    }
    return 0;
}