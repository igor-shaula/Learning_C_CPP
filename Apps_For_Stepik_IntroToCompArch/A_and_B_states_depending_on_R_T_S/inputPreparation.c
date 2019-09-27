#include <stdio.h>
#include "types.h"

void fillRSTvalues(RST *rstPtr)
{
    BOOL r, s, t;

    printf("\nEnter R:");
    // scanf("%d", &(rst.r));
    scanf("%d", &r);
    // scanf("%d", &(*rstPtr).r);
    // printf("R = %d", rst.r);
    printf("R = %d", r);

    printf("\nEnter S:");
    // scanf("%d", &(rst.s));
    scanf("%d", &s);
    // scanf("%d", &(*rstPtr).s);
    // printf("S = %d", rst.s);
    printf("S = %d", s);

    printf("\nEnter T:");
    // scanf("%d", &(rst.t));
    scanf("%d", &t);
    // scanf("%d", &(*rstPtr).t);
    // printf("T = %d", rst.t);
    printf("T = %d", t);

    (*rstPtr).r = r;
    (*rstPtr).s = s;
    (*rstPtr).t = t;
}