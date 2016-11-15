#include <stdio.h>

typedef int ElementType;


void ShellSort(ElementType Array[],int N)
{
    int ShellIncre;
    int i,j,k;
    ElementType Tmp;

    for (ShellIncre=1;ShellIncre*2<=N;ShellIncre*=2);

    for (;ShellIncre>0;ShellIncre/=2)
    {
        for (i=0;i<N;i++)
        {
            for (j=i+ShellIncre;j<N;j+=ShellIncre)
            {
                Tmp=Array[j];
                for (k=j;k-ShellIncre>=0 && Array[k-ShellIncre]>Tmp;k-=ShellIncre)
                    Array[k]=Array[k-ShellIncre];
                if (k>=0)
                    Array[k]=Tmp;
            }
            if (j>=N)
                break;
        }
    }
}

void ShellSort2(ElementType Array[],int N)
{
    ElementType Tmp;
    int P,i,ShellIncre;

    for (ShellIncre=1;ShellIncre*2<=N;ShellIncre*=2);

    for (;ShellIncre>0;ShellIncre/=2)
    {
        for (P=ShellIncre;P<N;P++)
        {
            Tmp=Array[P];
            for (i=P;i>=ShellIncre && Array[i-ShellIncre]>Tmp;i-=ShellIncre)
                Array[i]=Array[i-ShellIncre];
            Array[i]=Tmp;
        }
    }
}
int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    ShellSort2(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
