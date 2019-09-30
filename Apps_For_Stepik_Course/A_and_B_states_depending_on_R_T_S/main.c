#include <stdio.h>
#include "debugFunctions.h"
#include "detectionLogic.h"
#include "inputPreparation.h"
#include "types.h"

int main(void)
{
    unsigned int dimension = 2 * 2 * 2; // 2 variants for each of R, S & T booleans

    RST dataSet[dimension]; // all possible variants of RST instances for processing

    // initialization of data for processing
    for (int i = 0; i < dimension; i++)
    {
        dataSet[i] = fillRST(i);
    }

    // processing of each data structure
    RST rst;
    for (size_t i = 0; i < dimension; i++)
    {
        rst = dataSet[i];
        detect_A_and_B(rst.r, rst.s, rst.t);
        printf("\n");
    }

    return 0;
}