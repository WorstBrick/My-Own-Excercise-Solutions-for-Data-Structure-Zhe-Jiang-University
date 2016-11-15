#include "Interface.h"


void MergeOperationModified(ElementType A[],ElementType Tmp[],Position Leftstart,Position RightStart,Position RightEnd)
{
    Position k=Leftstart;
    Position LeftEnd=RightStart-1;

    while (Leftstart<=LeftEnd && RightStart<=RightEnd)
    {
        if (A[Leftstart]<A[RightStart])
            Tmp[k]=A[Leftstart++];
        else
            Tmp[k]=A[RightStart++];
        k++;
    }

    while (Leftstart<=LeftEnd)
    {
        Tmp[k]=A[Leftstart++];
        k++;
    }

    while (RightStart<=RightEnd)
    {
        Tmp[k]=A[RightStart++];
        k++;
    }
}

void CoreMerge(ElementType A[],ElementType Tmp[],int Num,int Length)
{
    Position i;

    for (i=0;i<=Num-2*Length;i+=2*Length)
        MergeOperationModified(A,Tmp,i,i+Length,i+2*Length-1);
    if (i+Length<Num)
        MergeOperationModified(A,Tmp,i,i+Length,Num-1);
    else
        for (;i<Num;i++)
            Tmp[i]=A[i];
}

/*void MergeSort(ElementType A[],int N)
{
    int Length=1;
    ElementType Tmp=(ElementType *)malloc(N*sizeof(ElementType));

    while (Length<N)
    {
        CoreMerge(A,Tmp,N,Length);
        Length*=2;
        CoreMerge(Tmp,A,N,Length);
        Length*=2;
    }

    free(Tmp);
}*/

bool CheckSequence(ElementType A[],ElementType Semi[],int N)
{
    Position i;

    for (i=0;i<N;i++)
        if (A[i]!=Semi[i])
            return false;
    return true;
}

bool MergeSortUntilEnough(ElementType A[],ElementType Semi[],ElementType Tmp[],int N,int Enough)
{
    int Length=1;
    bool flag=false;

    while (Length<Enough)
    {
        CoreMerge(A,Tmp,N,Length);
        Length*=2;
        if (Length>=Enough)
        {
            flag=true;
            break;
        }
        CoreMerge(Tmp,A,N,Length);
        Length*=2;
    }

    return flag;
}

void OneInsertion(ElementType Semi[],Position k)
{
    ElementType X=Semi[k];

    for (;k>0 && Semi[k-1]>X;k--)
        Semi[k]=Semi[k-1];
    Semi[k]=X;
}

Position FindReverseIndex(ElementType Semi[],int N)
{
    Position i;
    N--;

    for (i=0;i<N && Semi[i]<=Semi[i+1];i++);

    return (i+1);
}
