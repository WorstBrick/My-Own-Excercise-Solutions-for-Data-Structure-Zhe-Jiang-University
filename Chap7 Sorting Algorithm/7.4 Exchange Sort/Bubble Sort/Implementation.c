#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;

void Swap(ElementType Array[],int i,int j)
{
    ElementType Tmp=Array[i];
    Array[i]=Array[j];
    Array[j]=Tmp;
}

void BubbleSort(ElementType Array[],int N)
{
    int End,i;
    bool flag=false;

    for (End=N-1;End>0;End--)
    {
        for (i=0;i<End;i++)
        {
            if (Array[i]>Array[i+1])
            {
                Swap(Array,i,i+1);
                flag=true;
            }
        }
        if (flag)
            break;
    }
}
int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    BubbleSort(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
