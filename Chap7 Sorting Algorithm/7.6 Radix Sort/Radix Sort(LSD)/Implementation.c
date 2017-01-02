#include "Interface.h"

Bucket InitBucket(int MaxSize)
{
    Bucket B=(Bucket)malloc(MaxSize*sizeof(struct BNode));
    int i;

    for (i=0;i<MaxSize;i++)
        B[i].Head=B[i].Tail=NULL;

    return B;
}

int GetDigit(ElementType X,int D)
{
    int i;

    for (i=1;i<D;i++)
        X/=RADIX;

    return (X%RADIX);
}
void RadixSort(ElementType A[],int N)
{
    Bucket B=InitBucket(RADIX);
    int D,i,Di;
    PtrToEleNode List=NULL;
    PtrToEleNode NewNode,Tmp;


    for (i=0;i<N;i++)
    {
        NewNode=(EleList)malloc(sizeof(struct EleNode));
        NewNode->X=A[i];
        NewNode->Next=List;
        List=NewNode;
    }

    for (D=1;D<=MAXDIGIT;D++)
    {
        while (List)
        {
            Tmp=List->Next;
            Di=GetDigit(List->X,D);
            List->Next=NULL;
            if (B[Di].Head==NULL)
                B[Di].Head=B[Di].Tail=List;
            else
            {
                B[Di].Tail->Next=List;
                B[Di].Tail=List;
            }
            List=Tmp;
        }

        for (i=RADIX-1;i>=0;i--)
        {
            if (B[i].Head!=NULL)
            {
                B[i].Tail->Next=List;
                List=B[i].Head;
                B[i].Head=B[i].Tail=NULL;
            }
        }
    }

    for (i=0;i<N;i++)
    {
        A[i]=List->X;
        Tmp=List;
        List=List->Next;
        free(Tmp);
    }
    free(B);
}
