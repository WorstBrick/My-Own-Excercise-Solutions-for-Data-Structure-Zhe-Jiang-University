#include "Definition.h""
#include <stdlib.h>
#include <stdio.h>
Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof *S);
    S->Next=NULL;

    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Next==NULL);
}

bool Push(Stack S,ElementType X)
{
    PtrToSNode new=(PtrToSNode)malloc(sizeof *new);
    new->Data=X;
    new->Next=Top->Next;
    Top->Next=new;
    return true;
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("The stack is empty.\n");
        return ERROR;
    }

    ElemenType X=S->Next->Data;
    PtrToSNode temp=S->Next;
    S->Next=temp->Next;
    free(temp);
    return X;
}
