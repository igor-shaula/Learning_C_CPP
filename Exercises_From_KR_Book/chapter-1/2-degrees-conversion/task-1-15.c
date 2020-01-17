// updated variant of showing a table with degrees in Fahrenheit & Celcius - now using functions

#include <stdio.h>

int calculateCelcius(int fahrenheit) {
    return 5 * (fahrenheit - 32) / 9;
}

void printBoth(int fahrenheit, int celcius) {
    printf("%d\t%d\n", fahrenheit, celcius);
}

void processInLoop(int fahrenheit, int upperBound, int step) {
    while (fahrenheit <= upperBound) {
        printBoth(fahrenheit, calculateCelcius(fahrenheit));
        fahrenheit += step;
    }
}

int main() {
    processInLoop(0, 300, 10);
    return 0;
}