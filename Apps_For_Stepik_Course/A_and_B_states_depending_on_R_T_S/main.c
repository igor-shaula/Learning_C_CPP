#include "headers/types.h"
#include "headers/detectionLogic.h"
#include "headers/inputPreparation.h"
#include "headers/userUI.h"

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
    showSummary(variantsTotal);

    return 0;
}