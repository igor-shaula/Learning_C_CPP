// output for diapason of values for every primitive type

#include <stdio.h>
#include <limits.h>
#include <float.h>

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

void printUpperFloatLimit() {
    float f = 1.0f;
    unsigned long long counter = 0;
    while (f >= 0.0f) {
        printf("%.40f %llu\n", f, counter); // `inf`
        if ((f * 10.0f) == f) {
            printf("last growing value: %f %llu\n", f, counter); // `inf`
            break;
        } else {
            f *= 10.0f;
            ++counter;
        }
    }
}

void printLowerFloatLimit() {
    float f = 1.0f;
    unsigned long long counter = 0;
    while (f >= 0.0f) {
        printf("%.80f %llu\n", f, counter);
        if ((f * 0.1f) == f) {
            printf("last falling value: %.80f %llu\n", f, counter);
            break;
        } else {
            f *= 0.1f;
            ++counter;
        }
    }
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
    // all for float:
    printUpperFloatLimit();
    printLowerFloatLimit();
    printf("%d\n", 1000000000000.0f == 10.0f * 100000000000.0f);
    printf("%d\n", 0.01f == 1.0f * 0.01f);
    return 0;
}