#include "Interface.h"

int main(void)
{
    int MaxSize,N,K,i;
    scanf("%d %d %d",&MaxSize,&N,&K);
    Stack S=CreateStack(MaxSize);

    for (i=0;i<K;i++)
    {
        if (IsPopSequence(N,S))
            puts("Yes");
        else
            puts("No");
        CleanStack(S);
        fflush(stdin);
    }

    return 0;
}
