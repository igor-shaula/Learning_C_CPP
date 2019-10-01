#include <stdio.h>
#include "../headers/types.h"

// void fillRSTvalues(RST *rstPtr)
// {
//     printf("Enter R:");
//     scanf("%d", &(*rstPtr).r);

//     printf("Enter S:");
//     scanf("%d", &(*rstPtr).s);

//     printf("Enter T:");
//     scanf("%d", &(*rstPtr).t);
// }

// RST* generateDataSet(void)
// {
//     RST dataSet[8] = {
//         {0, 0, 0},
//         {0, 0, 1},
//         {0, 1, 0},
//         {0, 1, 1},
//         {1, 0, 0},
//         {1, 0, 1},
//         {1, 1, 0},
//         {1, 1, 1}};
//     return dataSet;
// }

RST fillRST(int number)
{
    RST rst;
    rst.r = (number >> 2) & 1;
    rst.s = (number >> 1) & 1;
    rst.t = number & 1;
    return rst;
}