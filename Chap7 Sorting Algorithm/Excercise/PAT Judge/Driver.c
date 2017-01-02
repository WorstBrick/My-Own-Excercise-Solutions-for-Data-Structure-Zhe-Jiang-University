#include "Interface.h"

extern int DIGITQ;

int main(void)
{
    int N,M,K,i;
    scanf("%d %d %d",&N,&K,&M);
    int FullMarks[K];
    int TotalFullMarks=0;

    for (i=0;i<K;i++)
    {
        scanf("%d",&FullMarks[i]);
        TotalFullMarks+=FullMarks[i];
    }
    for (DIGITQ=0;TotalFullMarks!=0;DIGITQ++)
        TotalFullMarks/=RADIX;

    UserList U=InitUserList(N);
    Table T=InitTable(N);
    BuildUserList(U,FullMarks,M,K);
    Bucket B=InitBucket(RADIX);
    FullMarkQuantBucketSort(T,U,B,N,K);
    TotalMarkRadixSort(T,U,B,N);

    ShowRank(T,U,N,K);

    return 0;
}
