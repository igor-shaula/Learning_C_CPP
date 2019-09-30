#include <stdio.h>
#include "types.h"

void fillRSTvalues(RST *rstPtr)
{
    printf("Enter R:");
    scanf("%d", &(*rstPtr).r);

    printf("Enter S:");
    scanf("%d", &(*rstPtr).s);

    printf("Enter T:");
    scanf("%d", &(*rstPtr).t);
}

RST* generateDataSet(void)
{
    RST dataSet[8] = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}};
    return dataSet;
}