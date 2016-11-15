#include "Interface.h"

static void Max(int a,int b)
{
    return (a>b? a : b);
}


int GetHeight(AVLTree T)
{
    int LHeight,Rheight;

    if (!T)
       return 0;
    else
    {
        LHeight=GeiHeight(T->Left);
        RHeight=GetHeight(T->Right);
        return (LHeight>Rheight? LHeight:Rheight)+1;
    }
}

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left),A->Height)+1;

    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B=A->Right;
    A->Right=B->Left;
    B->Left=A;

    A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=Max(A->Height,GetHeight(B->Right))+1;

    return B;
}

AVLTree DoubleLeftRightRoration(AVLTree A)
{
    A->Left=SingleRightRotation(A->Left);
    A=SingleLeftRotation(A);

    return A;
}

AVLTree DoubleRightLeftRoration(AVLTree A)
{
    A->Right=SingleLeftRotation(A->Right);

    return SingleRightRotation(A);
}


AVLTree Insert(AVLTree T,ElementType X)
{
    if (!T)
    {
        T=(AVLTree)malloc(sizeof(*T));
        T->Data=X;
        T->Height=1;
        T->Left=T->Right=NULL;
    }
    else if(X<T->Data)
    {
        T->Left=Insert(T->Left,X);
        if (GetHeight(T->Left)-GeiHeight(T->Right)==2)
            if (X<T->Left->Data)
                T=SingleLeftRotation(T);
            else
                T=DoubleLeftRightRoration(T);
    }
    else if (X>T->Data)
    {
        T->Right=Insert(T->Right,X);
        if (GetHeight(T->Left)-GetHeight(T->Right)==-2)
            if (X>T->Right->Data)
                T=SingleRightRotation(T);
            else
                T=DoubleRightLeftRoration(T);
    }

    T->Height=Max(GetHeight(T->Left),GetHeight(T->Right))+1;

    return T;
}
