#include <stdio.h>
#include "../headers/types.h"
#include "../headers/baseLogicBlocks.h"

BOOL detect_A(BOOL r, BOOL s, BOOL t) // inner function
{
    return OR(r, NOR(r, t));
}

BOOL detect_B(BOOL r, BOOL s, BOOL t) // inner function
{
    return AND(NOT(s), NOR(r, t));
}

AB detect_A_and_B(BOOL r, BOOL s, BOOL t) // inner function
{
    BOOL a = detect_A(r, s, t);
    BOOL b = detect_B(r, s, t);
    AB ab = {a, b};
    return ab;
}

evaluateLogic(RST dataSet[], AB resultSet[])
{
    for (size_t i = 0; i < DIMENSION; i++)
    {
        resultSet[i] = detect_A_and_B(dataSet[i].r, dataSet[i].s, dataSet[i].t);
    }
}

ui countVariations(AB *resultSet)
{
    ui result = 1; // even if all values are the same - we still have at least 1 variation - the very first array element

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