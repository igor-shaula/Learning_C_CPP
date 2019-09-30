#include <stdio.h>
#include "debugFunctions.h"
#include "detectionLogic.h"
#include "inputPreparation.h"
#include "types.h"

RST fillRST(int number)
{
    RST rst;
    rst.r = (number >> 2) & 1;
    rst.s = (number >> 1) & 1;
    rst.t = number & 1;
    return rst;
}

int main(void)
{
    /* 1 - creating new empty bucket for all input booleans */

    // debugInput();
    // debugLogic(&rst);

    /* 2 - setting needed starting input values */

    unsigned int dimension = 2 * 2 * 2; // 2 variants for each of R, S & T booleans

    RST dataSet[dimension];

    for (size_t i = 0; i < dimension; i++)
    {
        dataSet[i] = fillRST(i);
    }

    // fillRSTvalues(&rst);

    RST rst = {FALSE, FALSE, FALSE};
    for (size_t i = 0; i < dimension; i++)
    {
        // detect_A_and_B(rst.r, rst.s, rst.t);
        rst = dataSet[i];
        detect_A_and_B(rst.r, rst.s, rst.t);
    }

    printf("\n");
    return 0;
}