#include <stdio.h>
#include "../headers/types.h"

void debugInput(void)
{
    int n = 9;
    int *p = &n;
    scanf("%d", p);
    scanf("%d", &n);
    printf("*p = %d", *p);
    printf("\nn = %d", n);
}

void debugLogic(RST *rstPtr)
{
    BOOL r, s, t;
    r = (*rstPtr).r;
    s = (*rstPtr).s;
    t = (*rstPtr).t;
    printf("\nr = %d, s = %d, t = %d\n", r, s, t);
    printf("\nr|t:%d", r | t);
    printf("\nr||t:%d", r || t);
    printf("\nr&t:%d", r & t);
    printf("\nr&&t:%d", r && t);
    printf("\n~r:%d", !r);
    printf("\n~t:%d", !t);
}

char *getString()
{
    char s[] = "something\0";
    char *p = (char *)malloc(sizeof(s));
    strcpy(p, s);
    return p;
}

char getSecondChar()
{
    char hh[] = "anything\0";
    return *(hh + 1);
}

RST getTestRST()
{
    RST rst = {0, 0, 0};
    rst.r = 1;
    rst.s = 2;
    rst.t = 3;
    printf("\n&inner RST = %d", &rst);
    return rst;
}