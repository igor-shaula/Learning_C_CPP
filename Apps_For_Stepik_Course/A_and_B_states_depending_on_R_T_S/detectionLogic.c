#include <stdio.h>

BOOL detect_A(BOOL r, BOOL s, BOOL t)
{
    BOOL a = r || !(r || t);
    return a;
}

BOOL detect_B(BOOL r, BOOL s, BOOL t)
{
    BOOL b = !s && !(r || t);
    return b;
}

void detect_A_and_B(BOOL r, BOOL s, BOOL t)
{
    BOOL a = detect_A(r, s, t);
    printf("\nR=%d, S=%d, T=%d -> A=%d", r, s, t, a);
    BOOL b = detect_B(r, s, t);
    printf("\nR=%d, S=%d, T=%d -> B=%d", r, s, t, b);
}