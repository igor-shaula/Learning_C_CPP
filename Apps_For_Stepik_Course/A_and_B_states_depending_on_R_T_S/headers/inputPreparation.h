#include "types.h"

void fillDataSet(RST dataSet[], const ui dimension);

/*
as a result we have to get all possible variants of RST structures - as following:
RST dataSet[2 * 2 * 2] = {
   {0, 0, 0},
   {0, 0, 1},
   {0, 1, 0},
   {0, 1, 1},
   {1, 0, 0},
   {1, 0, 1},
   {1, 1, 0},
   {1, 1, 1}
};
*/