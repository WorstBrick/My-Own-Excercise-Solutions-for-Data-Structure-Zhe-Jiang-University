#include "Interface.h"

Stack * CreateStack(int Size)
{
    Stack * S=(Stack *)malloc(sizeof(*S));
    S->Size=Size;
    S->Data=(char *)malloc(Size*sizeof(char));
    S->Rear=-1;

    return S;
}

bool IsEmpty(Stack * S)
{
    return (S->Rear==-1);
}

bool IsFull(Stack * S)
{
    return (S->Rear==S->Size-1);
}

bool Push(char ch,Stack * S)
{
    if (IsFull(S))
        return false;
    (S->Data)[++(S->Rear)]=ch;
    return true;
}

bool Pop(Stack * S)
{
    if (IsEmpty(S))
        return false;
    (S->Rear)--;
    return true;
}
