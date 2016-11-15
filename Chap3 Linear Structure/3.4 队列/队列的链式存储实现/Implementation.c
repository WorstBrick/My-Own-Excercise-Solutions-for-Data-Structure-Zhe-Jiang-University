#include "Definition.h"

//�������ľ���ʵ��
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

    if (Q->Front==Q->Rear)   //������ֻ��һ��Ԫ��,ɾ���������Ϊ��
        Q->Front=(Q->Rear=NULL);
    else
        Q->Front=temp->Next;

    ElementType X=temp->Data;
    free(temp);

    return true;
}
