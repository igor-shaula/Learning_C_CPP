#include <stdio.h>
#include "../headers/types.h"

/*
as a result we have to get all possible variants of RST structures - as following:
RST dataSet[2 * 2 * 2] = {
   {0, 0, 0},
   {0, 0, 1},
   {0, 1, 0},
   {0, 1, 1},
   {1, 0, 0},
   {1, 0, 1},
   {1, 1, 0},
   {1, 1, 1}
};
*/
RST fillRST(ui number) // inner function
{
    RST rst;
    rst.r = (number >> 2) & 1; // elder bit
    rst.s = (number >> 1) & 1; // medium bit
    rst.t = number & 1;        // lesser bit
    return rst;
}

RST **prepareDataSet() // not used for now
{
    RST dataSet[DIMENSION];
    // initialization of data for processing
    for (int i = 0; i < DIMENSION; i++)
    {
        dataSet[i] = fillRST(i);
    }
    return dataSet;
}

void fillDataSet(RST dataSet[])
{
    // initialization of data for processing
    for (int i = 0; i < DIMENSION; i++)
    {
        dataSet[i] = fillRST(i);
    }
}