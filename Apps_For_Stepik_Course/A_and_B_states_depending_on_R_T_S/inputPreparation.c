#include <stdio.h>
#include "types.h"

void fillRSTvalues(RST *rstPtr)
{
    printf("Enter R:");
    scanf("%d", &(*rstPtr).r);

    printf("Enter S:");
    scanf("%d", &(*rstPtr).s);

    printf("Enter T:");
    scanf("%d", &(*rstPtr).t);
}