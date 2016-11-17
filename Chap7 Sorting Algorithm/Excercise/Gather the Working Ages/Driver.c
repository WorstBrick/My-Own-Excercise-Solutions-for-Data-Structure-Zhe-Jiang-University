#include <stdio.h>

//就是个桶排序,50个桶,大于10^5的数据量
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
