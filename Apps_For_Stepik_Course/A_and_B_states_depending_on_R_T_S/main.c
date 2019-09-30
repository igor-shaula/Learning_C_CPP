#include <stdio.h>
#include "debugFunctions.h"
#include "detectionLogic.h"
#include "inputPreparation.h"
#include "types.h"

int main(void)
{
    // all possible variants of RST instances are kept here
    RST dataSet[DIMENSION];

    // initialization of data for processing
    for (int i = 0; i < DIMENSION; i++)
    {
        dataSet[i] = fillRST(i);
    }

    // processing of each data structure
    RST rst;
    AB resultSet[DIMENSION];
    for (size_t i = 0; i < DIMENSION; i++)
    {
        rst = dataSet[i];
        resultSet[i] = detect_A_and_B(rst.r, rst.s, rst.t);
        printf("\n");
    }

    for (int i = 0; i < DIMENSION; i++)
    {
        printf("A = %d, B = %d\n", resultSet[i].a, resultSet[i].b);
    }

    return 0;
}