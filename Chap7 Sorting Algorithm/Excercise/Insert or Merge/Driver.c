#include "Interface.h"

int main(void)
{
    int N,i;
    scanf("%d",&N);

    Position k;
    ElementType * A=(ElementType *)malloc(N*sizeof(ElementType));
    ElementType * Tmp=(ElementType *)malloc(N*sizeof(ElementType));
    ElementType * Semi=(ElementType *)malloc(N*sizeof(ElementType));
    for (i=0;i<N;i++)
        scanf("%d",&A[i]);
    for (i=0;i<N;i++)
        scanf("%d",&Semi[i]);

    k=FindReverseIndex(Semi,N);

    if (MergeSortUntilEnough(A,Semi,Tmp,N,k))
    {
        if (CheckSequence(Tmp,Semi,N))
        {
            puts("Merge Sort");
            CoreMerge(Tmp,Semi,N,k);
        }
        else
        {
            puts("Insertion Sort");
            OneInsertion(Semi,k);
        }
    }
    else
    {
        if (CheckSequence(A,Semi,N))
        {
            puts("Merge Sort");
            CoreMerge(A,Semi,N,k);
        }
        else
        {
            puts("Insertion Sort");
            OneInsertion(Semi,k);
        }
    }

    printf("%d",Semi[0]);
    for (i=1;i<N;i++)
        printf(" %d",Semi[i]);

    return 0;
}
