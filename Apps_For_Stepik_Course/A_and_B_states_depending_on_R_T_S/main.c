#include <stdio.h>
#include <unistd.h>
#include "debugFunctions.h"
#include "detectionLogic.h"
#include "inputPreparation.h"
#include "types.h"

int main(void)
{
    /* 1 - creating new empty bucket for all input booleans */
    RST rst = {FALSE, FALSE, FALSE};

    // debugInput();
    // debugLogic(&rst);

    /* 2 - setting needed starting input values */
    fillRSTvalues(&rst);

    detect_A_and_B(rst.r, rst.s, rst.t);

    printf("\n");
    return 0;
}