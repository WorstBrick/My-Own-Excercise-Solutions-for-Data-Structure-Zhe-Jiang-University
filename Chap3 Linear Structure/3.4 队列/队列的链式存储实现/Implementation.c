#include "Definition.h"

//操作集的具体实现
bool IsEmpty(Queue Q)
{
    return (Q->Front==NULL);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("The queue is empty.\n")
        return ERROR;
    }

    PtrToNode temp=Q->Front;

    if (Q->Front==Q->Rear)   //若队列只有一个元素,删除后队列设为空
        Q->Front=(Q->Rear=NULL);
    else
        Q->Front=temp->Next;

    ElementType X=temp->Data;
    free(temp);

    return true;
}
