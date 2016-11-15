#include "Interface.h"

int main(void)
{
    int N,M,i,j;
    ElementType X;

    scanf("%d %d",&N,&M);
    MinHeap H=InitHeap(N);

    for (i=0;i<N;i++)
    {
        scanf("%d",&X);
        Insert(H,X);
    }

    for (i=0;i<M;i++)
    {
        scanf("%d",&j);
        ShowPath(H,j);
        if (i!=M-1)
            printf("\n");
    }

    return 0;
}
