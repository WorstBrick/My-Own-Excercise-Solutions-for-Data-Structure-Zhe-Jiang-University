#include <stdio.h>

typedef int ElementType;

void Swap(ElementType Array[],int i,int j)
{
    ElementType Tmp=Array[i];
    Array[i]=Array[j];
    Array[j]=Tmp;
}

void SimpleSelectionSort(ElementType Array[],int N)
{
    ElementType TmpMinIndex;
    int i,j;

    for (i=0;i<N;i++)
    {
        for (j=i+1,TmpMinIndex=i;j<N;j++)
        {
            if (Array[j]<Array[TmpMinIndex])
                TmpMinIndex=j;
        }
        Swap(Array,i,TmpMinIndex);
    }
}

int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    SimpleSelectionSort(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
