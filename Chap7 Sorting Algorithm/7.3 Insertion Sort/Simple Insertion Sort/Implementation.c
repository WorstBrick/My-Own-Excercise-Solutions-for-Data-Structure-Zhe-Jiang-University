#include <stdio.h>

typedef int ElementType;

/*void Swap(ElementType Array[],int i,int j)
{
    ElementType Tmp=Array[i];
    Array[i]=Array[j];
    Array[j]=Tmp;
}*/

void SimpleInsertionSort(ElementType Array[],int N)
{
    int i,j;
    ElementType Tmp;

    for (i=1;i<N;i++)
    {
        Tmp=Array[i];
        for (j=i;j>0 && Array[j-1]>Tmp;j--)
            Array[j]=Array[j-1];
        Array[j]=Tmp;
    }
}
int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    SimpleInsertionSort(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
