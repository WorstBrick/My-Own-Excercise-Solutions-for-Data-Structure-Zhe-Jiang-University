#include "Definition.h"

//操作集的具体实现
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof *Q);
    Q->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    Q->Front=0;
    Q->Rear=0;
    Q->MaxSize=MaxSize;

    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%Q->MaxSize==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
    if (IsFull(Q))
    {
        printf("The Queue is fully.\n");
        return false;
    }
    Q->Rear=(Q->Rear+1)%Q->MaxSize;
    Q->Data[Q->Rear]=X;
    return true;
}

bool IsEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("The queue is empty.\n");
        return ERROR;
    }
    Q->Front=(Q->Front+1)%(Q->MaxSize);
    ElementType X=Q->Data[Q->Front];

    return X;
}
