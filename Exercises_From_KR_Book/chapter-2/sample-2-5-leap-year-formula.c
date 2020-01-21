// detects if given year is a leap year

#include <stdio.h>

int isLeap(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    printf("year %d is leap: %c\n", 2020, (isLeap(2020) ? 'Y' : 'N'));
    return 0;
}