#include <stdio.h>
#include "headers/detectionLogic.h"
#include "headers/inputPreparation.h"
#include "headers/types.h"

int main(void)
{
    // all possible variants of RST instances are kept here
    RST dataSet[DIMENSION];
    fillDataSet(dataSet);

    // processing of each data structure
    AB resultSet[DIMENSION];
    evaluateLogic(dataSet, resultSet);

    // just printing results - everything has already been done
    for (int i = 0; i < DIMENSION; i++)
    {
        printf("R=%d, S=%d, T=%d -> ", dataSet[i].r, dataSet[i].s, dataSet[i].t);
        printf("A=%d, B=%d", resultSet[i].a, resultSet[i].b);
        printf("\n");
    }

    ui variantsTotal = countVariations(&resultSet);

    printf("total count of all possible variants is %d", variantsTotal);

    printf("\n");
    return 0;
}