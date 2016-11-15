#include "Interface.h"

Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof(*S));
    S->MaxSize=MaxSize;
    S->Data=(BinTree *)malloc(MaxSize*sizeof(BinTree));
    S->Rear=0;

    return S;
}


bool IsFull(Stack S)
{
    return (S->Rear==S->MaxSize);
}

bool Push(Stack S,BinTree X)
{
    if (IsFull(S))
        return false;
    else
    {
        S->Data[(S->Rear)++]=X;
        return true;
    }
}


bool IsEmpty(Stack S)
{
    return (S->Rear==0);
}


BinTree Pop(Stack S)
{
    if (IsEmpty(S))
        return NULL;
    else
        return (S->Data[--(S->Rear)]);
}

BinTree CreateTree(void)
{
    extern ElementType * Buffer;
    if ((*Buffer)==NONODE)
        return NULL;
    else
    {
        BinTree BT=(BinTree)malloc(sizeof(*BT));
        BT->flag=0;
        BT->Data=(*Buffer);
        ++Buffer;
        BT->Left=CreateTree();
        ++Buffer;
        BT->Right=CreateTree();

        return BT;
    }
}

/*void PostorderTraversal(BinTree BT,Stack S)
{
    if (!BT)
        return;
    BinTree T=BT;
    Push(S,T);
    (T->flag)++;
    T=T->Left;
    while (T || !IsEmpty(S))
    {
        if (T)
        {
            if (T->flag==0)
            {
                Push(S,T);
                (T->flag)++;
                T=T->Left;
                continue;
            }
            else if (T->flag==1)
            {
                Push(S,T);
                (T->flag)++;
                T=T->Right;
                continue;
            }
            else if (T->flag==2)
            {
                printf("%d ",T->Data);
                T=Pop(S);
                continue;
            }
        }
        else
        {
            if (IsEmpty(S))
                continue;
            T=Pop(S);
            if (T->flag==1)
            {
                Push(S,T);
                (T->flag)++;
                T=T->Right;
                continue;
            }
            else if (T->flag==2)
            {
                printf("%d ",T->Data);
                T=Pop(S);
                continue;
            }
        }
    }

}*/


void PostorderTraversal(BinTree BT,Stack S)
{
    BinTree T=BT;

    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S,T);
            (T->flag)++;
            T=T->Left;
        }
        T=Pop(S);
        if (T->flag==1)
        {
            Push(S,T);
            (T->flag)++;
            T=T->Right;
        }
        else if (T->flag==2)
        {
            printf("%d ",T->Data);
            T=Pop(S);
        }
    }
}
