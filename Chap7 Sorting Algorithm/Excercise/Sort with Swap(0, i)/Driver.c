#include "Interface.h"

int main(void)
{
    int N;
    scanf("%d",&N);
    int A[N];
    Address Location=(Address)malloc(N*sizeof(int));

    BuildPermutation(A,Location,N);

    printf("%d",CalSwapTimes(A,Location,N));

    return 0;
}
