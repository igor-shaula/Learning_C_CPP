#include <stdio.h>
#include "../headers/types.h"

void showResults(RST dataSet[], AB resultSet[])
{
    for (int i = 0; i < DIMENSION; i++)
    {
        printf("R=%d, S=%d, T=%d -> ", dataSet[i].r, dataSet[i].s, dataSet[i].t);
        printf("A=%d, B=%d", resultSet[i].a, resultSet[i].b);
        printf("\n");
    }
}

void showSummary(ui variantsTotal)
{
    printf("total count of all possible variants is %d", variantsTotal);
    printf("\n");
}