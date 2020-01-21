// output for diapason of values for every primitive type

#include <stdio.h>
#include <limits.h>

void printUnsignedRange(int bytes) {
    int bits = 8 * bytes;
    unsigned long long to = (1LLU << (bits - 1)) + ((1LL << (bits - 1)) - 1);;
    printf("from 0 to %llu\n", to);
}

void printSignedRange(int bytes) {
    int bits = 8 * bytes;
    long long from = -(1LL << (bits - 1));
    long long to = (1LL << (bits - 1)) - 1;
    printf("from %lld to %lld\n", from, to);
}

int main() {
    // all for char:
    printf("Range of char: ");
    printSignedRange(sizeof(char));
    printf("min for char from limits.h: %d\n", CHAR_MIN);
    printf("max for char from limits.h: %d\n", CHAR_MAX);
    printf("signed min for char from limits.h: %d\n", SCHAR_MIN); // the same as CHAR_MIN
    printf("signed max for char from limits.h: %d\n", SCHAR_MAX); // the same as CHAR_MAX
    printf("Range of unsigned char: ");
    printUnsignedRange(sizeof(unsigned char));
    printf("unsigned max for char from limits.h: %u\n", UCHAR_MAX);
    // all for short:
    printf("Range of short: ");
    printSignedRange(sizeof(short));
    printf("signed min for short from limits.h: %d\n", SHRT_MIN);
    printf("signed max for short from limits.h: %d\n", SHRT_MAX);
    printf("Range of unsigned short: ");
    printUnsignedRange(sizeof(unsigned short));
    printf("unsigned range for int from limits.h: %u\n", USHRT_MAX);
    // all for int:
    printf("Range of int: ");
    printSignedRange(sizeof(int));
    printf("signed min for int from limits.h: %d\n", INT_MIN);
    printf("signed max for int from limits.h: %d\n", INT_MAX);
    printf("Range of unsigned int: ");
    printUnsignedRange(sizeof(unsigned int));
    printf("unsigned range for int from limits.h: %u\n", UINT_MAX);
    // all for long:
    printf("Range of long: ");
    printSignedRange(sizeof(long));
    printf("signed min for long from limits.h: %ld\n", LONG_MIN);
    printf("signed max for long from limits.h: %ld\n", LONG_MAX);
    printf("Range of unsigned long: ");
    printUnsignedRange(sizeof(unsigned long));
    printf("unsigned range for long from limits.h: %lu\n", ULONG_MAX);
    // all for long long:
    printf("Range of long long: ");
    printSignedRange(sizeof(long long));
    printf("signed min for long long from limits.h: %lld\n", LLONG_MIN);
    printf("signed max for long long from limits.h: %lld\n", LLONG_MAX);
    printf("Range of unsigned long long: ");
    printUnsignedRange(sizeof(unsigned long long));
    printf("unsigned range for int from limits.h: %llu\n", ULLONG_MAX);
    return 0;
}