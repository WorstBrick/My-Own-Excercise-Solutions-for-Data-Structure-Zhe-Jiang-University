#include "Interface.h"

Heap InitHeap(int Max)
{
    Heap H=(Heap)malloc(sizeof(*H));
    H->CurrentEle=0;
    H->StorageSpace=(CBT)malloc((Max+1)*sizeof(ElementType));
    H->StorageSpace[0]=Max;

    return H;
}

void UpFilt(Heap H,ElementType X)
{
    Position Child=H->CurrentEle,Parent=Child/2;

    while (Parent>0 && H->StorageSpace[Parent]>X)
    {
        H->StorageSpace[Child]=H->StorageSpace[Parent];
        Child=Parent;
        Parent=Child/2;
    }
    H->StorageSpace[Child]=X;
}

void HeapInsert(Heap H,ElementType X)
{
    H->StorageSpace[++(H->CurrentEle)]=X;
    UpFilt(H,X);
}

bool IsEmpty(Heap H)
{
    return (H->CurrentEle==0);
}

void DownFilt(Heap H)
{
    ElementType X=H->StorageSpace[1];
    Position Parent=1;
    Position Child=Parent*2;

    while (Child<=H->CurrentEle)
    {
        if (H->StorageSpace[Child]>H->StorageSpace[Child+1])
            Child++;
        if (X>H->StorageSpace[Child])
        {
            H->StorageSpace[Parent]=H->StorageSpace[Child];
            Parent=Child;
            Child=Parent*2;
        }
        else
            break;
    }
    H->StorageSpace[Parent]=X;
}

ElementType HeapDelete(Heap H)
{
    ElementType X=H->StorageSpace[1];
    H->StorageSpace[1]=H->StorageSpace[(H->CurrentEle)--];
    DownFilt(H);

    return X;
}

void HeapSort(ElementType A[],int N)
{
    Heap H=InitHeap(N);
    int i;

    for (i=0;i<N;i++)
        HeapInsert(H,A[i]);

    for (i=0;i<N;i++)
        A[i]=HeapDelete(H);
}
