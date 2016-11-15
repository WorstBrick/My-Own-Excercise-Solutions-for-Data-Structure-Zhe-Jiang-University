#include "Interface.h"

BTree InitBTree(int MaxSize)
{
    BTree BT=(BTree)malloc((MaxSize+1)*sizeof(ElementType));
    BT[0]=MaxSize;
    return BT;
}

void Insert(BTree BT)
{
    int i;
    int MaxSize=BT[0]+1;//不要忘了,顺序存储的二叉树,从下标为1处开始
    ElementType X;

    for (i=1;i<MaxSize;i++)
    {
        scanf("%d",&X);
        BT[i]=X;
    }
}


Position CommonAncestor(Position i,Position j)
{
    while (i!=1 && j!=1 && i!=j)
    {
        if (i>j)
            i/=2;
        else
            j/=2;
    }

    return (i==j?i:1);
}
