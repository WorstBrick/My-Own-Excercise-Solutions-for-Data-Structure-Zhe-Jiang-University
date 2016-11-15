#include "Interface.h"

int main(void)
{
    int N,i;
    scanf("%d",&N);
    ElementType A[N];

    for (i=0;i<N;i++)
        scanf("%d",&A[i]);

    SelectionSort(A,N);

    for (i=0;i<N-1;i++)
        printf("%d ",A[i]);
    printf("%d",A[i]);

    return 0;
}
