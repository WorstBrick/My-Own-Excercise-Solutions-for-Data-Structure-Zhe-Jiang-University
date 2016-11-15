#include "Interface.h"

int main(void)
{
    int N,Times;
    scanf("%d",&N);
    ElementType A[N];
    ElementType Copy[N];
    ElementType Semi[N];

    Position i;

    for (i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        Copy[i]=A[i];
    }

    for (i=0;i<N;i++)
        scanf("%d",&Semi[i]);

    Times=FindInsertTimes(Semi,N);
    InsertSortSomeTimes(Copy,Times);
    if (CheckSequence(Semi,Copy,N))
    {
        InsertOne(Copy,Times+1);
        puts("Insertion Sort");
        ShowSequence(Copy,N);
    }
    else
    {
        AdjustArrayToHeap(A,N);
        HeapSortModified(A,Semi,N);
        puts("Heap Sort");
        ShowSequence(A,N);
    }

    return 0;
}
