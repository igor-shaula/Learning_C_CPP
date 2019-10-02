#include <stdio.h>
#include "../headers/types.h"

RST fillRST(ui number) // inner function
{
    RST rst;
    rst.r = (number >> 2) & 1; // elder bit
    rst.s = (number >> 1) & 1; // medium bit
    rst.t = number & 1;        // lesser bit
    return rst;
}

void fillDataSet(RST dataSet[], const ui dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        dataSet[i] = fillRST(i);
    }
}