#include <stdio.h>
#include "headers/detectionLogic.h"
#include "headers/inputPreparation.h"
#include "headers/types.h"

int main(void)
{
    // all possible variants of RST instances are kept here
    RST dataSet[DIMENSION];

    RST** dataSetPtr = prepareDataSet();
    printf("dataSetPtr:%d", **dataSetPtr);

    // dataSet = dataSetPtr; // in fact dataSet is array of RST structs - the same as dataSetPtr

    // processing of each data structure
    RST rst;
    AB resultSet[DIMENSION];
    for (size_t i = 0; i < DIMENSION; i++)
    {
        rst = dataSet[i];
        resultSet[i] = detect_A_and_B(rst.r, rst.s, rst.t);
    }

    // just printing results - everything has already been done
    for (int i = 0; i < DIMENSION; i++)
    {
        rst = dataSet[i];
        printf("R=%d, S=%d, T=%d -> ", rst.r, rst.s, rst.t);
        printf("A=%d, B=%d", resultSet[i].a, resultSet[i].b);
        printf("\n");
    }

    unsigned int variantsTotal = countVariations(&resultSet);

    printf("total count of all possible variants is %d", variantsTotal);

    printf("\n");
    return 0;
}