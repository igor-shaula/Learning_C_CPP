#include "headers/types.h"
#include "headers/detectionLogic.h"
#include "headers/inputPreparation.h"
#include "headers/userUI.h"

int main(void)
{
    // all possible variants of RST instances are kept here
    RST dataSet[DIMENSION];
    fillDataSet(dataSet, DIMENSION);

    // processing of each data structure
    AB resultSet[DIMENSION];
    evaluateLogic(dataSet, resultSet, DIMENSION);

    // just printing results - everything has already been done
    showResults(dataSet, resultSet, DIMENSION);

    ui variantsTotal = countVariations(resultSet, DIMENSION);
    showSummary(variantsTotal);

    return 0;
}