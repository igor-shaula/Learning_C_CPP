#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c, nl, nw, ns, state;

    state = OUT;
    nl = nw = ns = 0;

    while ((c = getchar() != EOF))
    {
        ++ns;
        if (c == '\n' || c == ' ' || c == '\t')
        {
            state = OUT;
            if (c == '\n')
            {
                ++nl;
            }
        }
        else if (state == OUT)
        {
            ++nw;
            state = IN;
        }
    }
    printf("lines:%d ,words%d ,symbols%d\n", nl, nw, ns);
}