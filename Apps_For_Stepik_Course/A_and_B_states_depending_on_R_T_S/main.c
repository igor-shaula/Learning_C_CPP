#include <stdio.h>
#include "headers/detectionLogic.h"
#include "headers/inputPreparation.h"
#include "headers/userUI.h"
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
    showResults(dataSet, resultSet);

    ui variantsTotal = countVariations(&resultSet);

    printf("total count of all possible variants is %d", variantsTotal);

    printf("\n");
    return 0;
}