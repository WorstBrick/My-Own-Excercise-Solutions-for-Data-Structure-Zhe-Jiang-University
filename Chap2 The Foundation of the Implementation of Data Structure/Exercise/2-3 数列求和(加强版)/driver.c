#include <stdio.h>

int sum(int,int);
int main(void)
{
    printf("%d\n",CalSum(3,1));

    return 0;
}

int CalSum(int n,int a)
{
    int i,item=a,sum=a;

    for (i=0;i<n-1;i++)
    {
        item=item*10+a;
        sum+=item;
    }

    return sum;
}
