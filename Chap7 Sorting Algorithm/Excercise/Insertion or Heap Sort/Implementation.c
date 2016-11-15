#include "Interface.h"

static Position MaxOne(ElementType A[],int N,Position Parent)
{
    Position Child=Parent*2+1;
    if (Child<N-1)
        return (A[Child+1]>A[Child]?Child+1 : Child);
    else
        return Child;
}

static void DownFilt(ElementType A[],int N,Position Root)
{
    ElementType X=A[Root];
    Position Parent=Root,Child=MaxOne(A,N,Parent);

    while (Child<N && X<A[Child])
    {
        A[Parent]=A[Child];
        Parent=Child;
        Child=MaxOne(A,N,Parent);
    }

    A[Parent]=X;
}

void AdjustArrayToHeap(ElementType A[],int N)
{
    Position Root=((N-1)%2==0? (N-2)/2 : (N-1)/2);

    for (;Root>=0;Root--)
        DownFilt(A,N,Root);

}

int FindInsertTimes(ElementType Semi[],int N)
{
    Position i;

    for (i=0;i<N && Semi[i]<=Semi[i+1];i++);

    return i;
}

void InsertSortSomeTimes(ElementType Copy[],int Times)
{
    Position i,j;
    ElementType X;

    for (i=1;i<=Times;i++)
    {
        for (X=Copy[i],j=i;j>0 && Copy[j-1]>X;j--)
            Copy[j]=Copy[j-1];
        Copy[j]=X;
    }
}

bool CheckSequence(ElementType Semi[],ElementType Copy[],int N)
{
    Position i;

    for (i=0;i<N;i++)
        if (Semi[i]!=Copy[i])
            return false;

    return true;
}

void InsertOne(ElementType Copy[],Position Index)
{
    ElementType X;

    for (X=Copy[Index];Index>0 && Copy[Index-1]>X;Index--)
            Copy[Index]=Copy[Index-1];
    Copy[Index]=X;
}

static void Swap(ElementType A[],Position i,Position j)
{
    ElementType Tmp=A[j];
    A[j]=A[i];
    A[i]=Tmp;
}

void HeapSortModified(ElementType A[],ElementType Semi[],int N)
{
    Position FinalEle=N-1;

    while (FinalEle>0)
    {
        Swap(A,0,FinalEle);
        N--;
        FinalEle--;
        DownFilt(A,N,0);
        if (A[FinalEle+1]!=Semi[FinalEle+1])
            break;
    }
}

void ShowSequence(ElementType A[],int N)
{
    int i;

    printf("%d",A[0]);
    for (i=1;i<N;i++)
        printf(" %d",A[i]);
}
