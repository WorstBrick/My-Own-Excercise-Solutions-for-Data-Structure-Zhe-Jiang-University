#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;

void Merge(ElementType A[],ElementType Tmp[],Position LeftStart,Position RightStart,Position RightEnd)
{
    Position LeftEnd=RightStart-1;
    int Num=RightEnd-LeftStart+1;
    Position k=LeftStart;

    while (LeftStart<=LeftEnd && RightStart<=RightEnd)
    {
        if (A[LeftStart]<A[RightStart])
            Tmp[k]=A[LeftStart++];
        else
            Tmp[k]=A[RightStart++];
        k++;
    }

    while (LeftStart<=LeftEnd)
    {
        Tmp[k]=A[LeftStart++];
        k++;
    }
    while (RightStart<=RightEnd)
    {
        Tmp[k]=A[RightStart++];
        k++;
    }

    for (k=0;k<Num;k++,RightEnd--)
        A[RightEnd]=Tmp[RightEnd];
}

void CoreRecursion(ElementType A[],ElementType Tmp[],Position LeftStart,Position RightEnd)
{
   if (LeftStart<RightEnd)
   {
       int Center=(RightEnd+LeftStart)/2;
       CoreRecursion(A,Tmp,LeftStart,Center);
       CoreRecursion(A,Tmp,Center+1,RightEnd);
       Merge(A,Tmp,LeftStart,Center+1,RightEnd);

   }
}
void MergeSort(ElementType A[],int N)
{
    ElementType * Tmp=(ElementType *)malloc(N*sizeof(ElementType));

    if (Tmp==NULL)
        return;
    else
    {
        CoreRecursion(A,Tmp,0,N-1);
        free(Tmp);
    }
}

int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    MergeSort(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
