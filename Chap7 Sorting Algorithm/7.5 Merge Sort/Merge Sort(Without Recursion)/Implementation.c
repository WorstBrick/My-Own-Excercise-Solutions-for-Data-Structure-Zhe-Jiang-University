#include "Interface.h"

Stack InitStack(int MaxNum)
{
    Stack S=(Stack)malloc(sizeof(*S));
    S->MaxNum=MaxNum;
    S->StorageSpace=(StorageMode)malloc(MaxNum*sizeof(SElement));
    S->LatestEle=0;

    return S;
}

bool IsFull(Stack S)
{
    return (S->LatestEle==S->MaxNum);
}

bool Push(Stack S,SElement X)
{
    if (IsFull(S))
        return false;
    else
    {
        S->StorageSpace[(S->LatestEle)++]=X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return (S->LatestEle==0);
}

SElement Pop(Stack S)
{
    if (IsEmpty(S))
        return NULL;
    else
        return (S->StorageSpace[--(S->LatestEle)]);
}

void MergeOperation(ElementType A[],ElementType Tmp[],Position LeftStart,Position RightStart,Position RightEnd)
{
    Position LeftEnd=RightStart-1;
    int Num=RightEnd-LeftStart+1;
    Position i=LeftStart;

    while (LeftStart<=LeftEnd && RightStart<=RightEnd)
    {
        if (A[LeftStart]<A[RightStart])
            Tmp[i]=A[LeftStart++];
        else
            Tmp[i]=A[RightStart++];
        i++;
    }

    while (LeftStart<=LeftEnd)
    {
        Tmp[i]=A[LeftStart++];
        i++;
    }

    while (RightStart<=RightEnd)
    {
        Tmp[i]=A[RightStart++];
        i++;
    }

    for (i=0;i<Num;i++,RightEnd--)
        A[RightEnd]=Tmp[RightEnd];
}

SElement NewEndPoints(Position Left,Position Right)
{
    SElement EndPoints=(SElement)malloc(sizeof(*EndPoints));
    EndPoints->Left=Left;
    EndPoints->Right=Right;

    return EndPoints;
}
void CoreSort(ElementType A[],ElementType Tmp[],Position LeftStart,Position RightEnd)
{
    int Num=RightEnd-LeftStart+1;
    Stack S=InitStack(Num*2);
    Position Center=(LeftStart+RightEnd)/2;
    SElement EndPoints=NewEndPoints(LeftStart,RightEnd);

    Push(S,EndPoints);

    RightEnd=Center;
    Center=(LeftStart+RightEnd)/2;

    while (!IsEmpty(S))
    {
        while (LeftStart<RightEnd && RightEnd<Num)
        {
            EndPoints=NewEndPoints(LeftStart,RightEnd);
            Push(S,EndPoints);
            RightEnd=Center;
            Center=(LeftStart+RightEnd)/2;
        }
        EndPoints=Pop(S);
        //printf("%d %d\n",EndPoints->Left,EndPoints->Right);
        MergeOperation(A,Tmp,EndPoints->Left,(EndPoints->Left+EndPoints->Right)/2+1,EndPoints->Right);
        if (S->LatestEle>0)
            RightEnd=S->StorageSpace[S->LatestEle-1]->Right;
        LeftStart=EndPoints->Right+1;
        Center=(LeftStart+RightEnd)/2;
        free(EndPoints);
    }
}

void MergeSort(ElementType A[],int N)
{
    ElementType * Tmp=(ElementType *)malloc(N*sizeof(ElementType));

    CoreSort(A,Tmp,0,N-1);
}
