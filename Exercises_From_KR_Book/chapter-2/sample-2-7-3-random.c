// generates pseudo-random value from 0 to 32767

#include <stdio.h>

unsigned long int next = 1;

void initializeRandom(int seed) {
    next = seed;
}

int random() {
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

int main() {
    initializeRandom(5);
    printf("%d", random());
}