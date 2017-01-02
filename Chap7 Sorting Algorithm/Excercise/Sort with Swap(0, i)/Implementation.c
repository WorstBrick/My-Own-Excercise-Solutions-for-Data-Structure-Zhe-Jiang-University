#include "Interface.h"

void Swap(int A[],Position i0,Position ik)
{
    A[i0]=A[ik];
    A[ik]=0;
}

void BuildPermutation(int A[],Address Location,int N)
{
    int i;

    for (i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        Location[A[i]]=i;
    }
}

int CalSwapTimes(int A[],Address Location,int N)
{
    int Times=0;
    Position i0=Location[0];
    Position Index;

    while (1)
    {
        if (i0!=0)
        {
            Index=Location[i0];
            Swap(A,i0,Index);
            Location[0]=Index;
            Location[i0]=i0;
            Times++;
            i0=Index;
        }
        else
        {
            for (Index=1;Index<N && A[Index]==Index;Index++)
                continue;
            if (Index==N)
                break;
            else
            {
                Location[0]=Index;
                Location[A[Index]]=0;
                Swap(A,i0,Index);
                Times++;
                i0=Index;
            }
        }
    }

    return Times;
}
