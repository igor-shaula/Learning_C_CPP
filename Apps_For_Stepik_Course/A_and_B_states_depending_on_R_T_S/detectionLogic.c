#include <stdio.h>
#include "types.h"
#include "baseLogicBlocks.h"

BOOL detect_A(BOOL r, BOOL s, BOOL t)
{
    // return = r || !(r || t);
    return _or(r, _nor(r, t));
}

BOOL detect_B(BOOL r, BOOL s, BOOL t)
{
    // return = !s && !(r || t);
    return _and(_not(s), _nor(r, t));
}

AB detect_A_and_B(BOOL r, BOOL s, BOOL t)
{
    BOOL a = detect_A(r, s, t);
    printf("\nR=%d, S=%d, T=%d -> A=%d", r, s, t, a);
    BOOL b = detect_B(r, s, t);
    printf("\nR=%d, S=%d, T=%d -> B=%d", r, s, t, b);
    AB ab = {a, b};
    return ab;
}