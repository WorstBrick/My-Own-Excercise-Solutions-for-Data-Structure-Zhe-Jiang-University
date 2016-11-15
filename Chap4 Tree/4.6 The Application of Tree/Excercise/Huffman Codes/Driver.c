#include "Interface.h"

//extern int CharFre[SIZE];
int main(void)
{
    int i,N,M;
    scanf("%d",&N);

    ReadFre(N);

    CalFre(N);
    scanf("%d",&M);
    for (i=0;i<M;i++)
    {
        if (JudgeHuff(N))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
