#include "types.h"

BOOL _not(BOOL input)
{
    return !input;
}

BOOL _and(BOOL b1, BOOL b2)
{
    return b1 && b2;
}

BOOL _or(BOOL b1, BOOL b2)
{
    return b1 || b2;
}

BOOL _nor(BOOL b1, BOOL b2)
{
    return !_or(b1, b2);
}