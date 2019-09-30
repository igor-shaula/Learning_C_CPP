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
    BOOL b = detect_B(r, s, t);
    AB ab = {a, b};
    return ab;
}

unsigned int countVariations(AB *resultSet)
{
    unsigned int result = 1; // even if all values are the same - we still have at least 1 variation - the very first array element

    for (int i = 1; i < DIMENSION; i++)
    {
        for (int j = 0; j < i; j++) // comparing to all previous array elements
        {
            if (resultSet[i].a != resultSet[j].a && resultSet[i].b != resultSet[j].b)
            {
                result++;
            }
        }
    }
    return result;
}