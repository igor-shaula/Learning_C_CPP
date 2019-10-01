#include "../headers/types.h"

BOOL NOT(BOOL input)
{
    return !input;
}

BOOL AND(BOOL b1, BOOL b2)
{
    return b1 && b2;
}

BOOL OR(BOOL b1, BOOL b2)
{
    return b1 || b2;
}

BOOL NOR(BOOL b1, BOOL b2)
{
    return !OR(b1, b2);
}