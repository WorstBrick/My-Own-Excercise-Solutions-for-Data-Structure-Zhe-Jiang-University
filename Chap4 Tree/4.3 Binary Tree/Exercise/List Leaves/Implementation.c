#include "Interface.h"
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof *Q);
    Q->Data=(ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    Q->Front=0;
    Q->Rear=0;
    Q->MaxSize=MaxSize;

    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%(Q->MaxSize+1)==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
    if (IsFull(Q))
        return false;
    else
    {
        Q->Data[Q->Rear]=X;
        Q->Rear=(Q->Rear+1)%(Q->MaxSize+1);
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
        return ERROR;
    else
    {
        ElementType X=Q->Data[Q->Front];
        Q->Front=(Q->Front+1)%(Q->MaxSize+1);
        return X;
    }
}

FakeTree InitTree(int N)
{
    FakeTree FT=(FakeTree)malloc(N*sizeof(struct FTNode));
    int i;

    for (i=0;i<N;i++)
        FT[i].Flag=true;

    return FT;
}

void ReadNode(FakeTree FT,int N)
{
    Node i;
    char Left,Right;

    getchar();
    for (i=0;i<N;i++)
    {
        scanf("%c %c",&Left,&Right);
        getchar();

    }
}
