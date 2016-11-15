#include "Interface.h"

ElementType * SortedBuf;
int i;

static AvlTree NewNode(ElementType X)
{
    AvlTree T=(AvlTree)malloc(sizeof(*T));
    T->Data=X;
    T->Left=T->Right=NULL;

    return T;
}


AvlTree InitAvlTree(ElementType X)
{
    AvlTree T=NewNode(X);
    return T;
}


int GetHeight(AvlTree T)
{
    if (T==NULL)
        return 0;
    else
    {
        int LeftHeight=GetHeight(T->Left);
        int RightHeight=GetHeight(T->Right);

        return (LeftHeight>RightHeight? LeftHeight+1:RightHeight+1);
    }
}


AvlTree RRRotate(AvlTree T)
{
    AvlTree Tmp=T;
    T=T->Right;
    Tmp->Right=T->Left;
    T->Left=Tmp;

    return T;
}

AvlTree LLRotate(AvlTree T)
{
    AvlTree Tmp=T;
    T=T->Left;
    Tmp->Left=T->Right;
    T->Right=Tmp;

    return T;
}

AvlTree RLRotate(AvlTree T)
{
    T->Right=LLRotate(T->Right);
    T=RRRotate(T);

    return T;
}

AvlTree LRRotate(AvlTree T)
{
    T->Left=RRRotate(T->Left);
    T=LLRotate(T);

    return T;
}

AvlTree Insert(AvlTree T,ElementType X)
{
    if (!T)
    {
        T=NewNode(X);
        return T;
    }
    else
    {
        if (X<T->Data)
            T->Left=Insert(T->Left,X);
        else
            T->Right=Insert(T->Right,X);
        if (GetHeight(T->Left)-GetHeight(T->Right)==-2)
        {
            if (X<T->Right->Data)
                T=RLRotate(T);
            else
                T=RRRotate(T);
        }
        else if (GetHeight(T->Left)-GetHeight(T->Right)==2)
        {
            if (X>T->Left->Data)
                T=LRRotate(T);
            else
                T=LLRotate(T);
        }

        return T;
    }
}

void AvlVisit(PtrToAVNode T)
{
    SortedBuf[i++]=T->Data;
}


void AvlInorder(AvlTree T)
{
    if (!T)
        return;
    else
    {
        AvlInorder(T->Left);
        AvlVisit(T);
        AvlInorder(T->Right);
    }
}

static double Log2(double N)
{
    return log(N)/log(2);
}

CBSTree InitCBStree(int N)
{
    CBSTree CT=(CBSTree)malloc(sizeof(*CT));
    int FHeight=(int)Log2(N);
    int Height=FHeight+1;
    int LowestLayer=N+1-(int)pow(2,FHeight);
    int MaxNum=(int)pow(2,Height)+LowestLayer*2-1;
    int i;

    CT->AllNode=(ElementType*)malloc((MaxNum+1)*sizeof(ElementType));
    CT->AllNode[0]=N;

    for (i=1;i<=N;i++)
        CT->AllNode[i]=UNMEANNING;
    for (;i<=MaxNum;i++)
        CT->AllNode[i]=NOSON;

    return CT;
}

void CBSVisit(CBSTree CT,Position j)
{
    CT->AllNode[j]=SortedBuf[i++];
}

void CBSInorder(CBSTree CT,Position j)
{
    if (CT->AllNode[j]==NOSON)
        return;
    else
    {
        CBSInorder(CT,2*j);
        CBSVisit(CT,j);
        CBSInorder(CT,2*j+1);
    }
}

void CBSLayerOrder(CBSTree CT)
{
    Position j;
    int N=CT->AllNode[0];

    for (j=1;j<N;j++)
        printf("%d ",CT->AllNode[j]);
    printf("%d",CT->AllNode[j]);
}
