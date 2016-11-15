#include "Interface.h"

MinHeap InitHeap(int MaxSize)
{
    MinHeap H=(MinHeap)malloc(sizeof(*H));
    H->Data=(ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->MaxSize=MaxSize;
    H->Size=0;
    H->Data[0]=GUARD;

    return H;
}

bool IsFull(MinHeap H)
{
    return (H->Size==H->MaxSize);
}

bool Insert(MinHeap H,ElementType X)
{
    if (IsFull(H))
        return false;
    else
    {
        H->Data[++H->Size]=X;
        int i;

        for (i=H->Size;H->Data[i/2]>X;i/=2)
            H->Data[i]=H->Data[i/2];
        H->Data[i]=X;
        return true;
    }
}

bool ShowPath(MinHeap H,int i)
{
    if (i>H->Size)
        return false;
    for (;i>0;i/=2)
    {
        printf("%d",H->Data[i]);
        if (i!=1)
            printf(" ");
    }
    return true;
}
