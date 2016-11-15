#include "Interface.h"

Stack CreatStack(int Size)
{
    Stack S=(Stack)malloc(sizeof(*S));
    S->Size=Size;
    S->Data=(int *)malloc(Size * sizeof(int));
    S->Rear=-1;

    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Rear==-1);
}

bool IsFull(Stack S)
{
    return (S->Rear==S->Size-1);
}

int Pop(Stack S)
{
    if (IsEmpty(S))
        return ERROR;
    return ((S->Data)[(S->Rear)--]);
}

bool Push(int tag,Stack S)
{
    if (IsFull(S))
        return false;
    (S->Data)[++(S->Rear)]=tag;
    return true;
}
