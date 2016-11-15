#include "Interface.h"
#include <stdio.h>

int main(void)
{
    int N,i;
    ElementType Data;

    scanf("%d",&N);
    scanf("%d",&Data);
    ATree AT=InitTree(Data);
    for (i=1;i<N;i++)
    {
        scanf("%d",&Data);
        AT=Insert(AT,Data);
    }
    printf("%d\n",AT->Data);

    return 0;
}
