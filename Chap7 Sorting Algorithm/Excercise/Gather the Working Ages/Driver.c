#include <stdio.h>

//���Ǹ�Ͱ����,50��Ͱ,����10^5��������
int main(void)
{
    int WorkingAge[51];
    int i,N,tmp;

    for (i=0;i<51;i++)
        WorkingAge[i]=0;

    scanf("%d",&N);

    for (i=0;i<N;i++)
    {
        scanf("%d",&tmp);
        WorkingAge[tmp]++;
    }

    for (i=0;i<51;i++)
    {
        if (WorkingAge[i]>0)
            printf("%d:%d\n",i,WorkingAge[i]);
    }

    return 0;
}
