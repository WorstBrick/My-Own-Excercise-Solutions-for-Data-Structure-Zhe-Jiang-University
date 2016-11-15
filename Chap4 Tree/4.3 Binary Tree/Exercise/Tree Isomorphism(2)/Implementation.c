#include "Interface.h"

Position FillTNode(BinTree BT,int quant)
{
    int i;
    ElementType Data;
    Position Left,Right;
    Position *P=(Position)calloc(quant,sizeof(Position));

    for (i=0;i<quant;i++)
    {
        scanf("%c %d %d",&Data,&Left,&Right);
        (BT[i]).Data=Data;
        if (Left=='-')
            Left=NOINFO;
        if (Right=='-')
            Right=NOINFO;
        if (Left>=0)
            P[Left]=1;
        if (Right>=0)
            P[Right]=1;
        (BT[i]).Left=Left;
        (BT[i]).Right=Right;
    }
    for (i=0;i<quant && !P[i];i++);
    return i;
}


BinTree InitTree(int quant)
{
    BinTree BT=(BinTree)malloc(quant*sizeof(*BT));

    return BT;
}


Position Find(BinTree BT,int quant,ElementType X)
{
    int i,j=NOTFOUND;

    for (i=0;i<quant;i++)
    {
        if ((BT[i]).Data==X)
        {
            j=i;
            break;
        }
    }

    return j;
}

void JudgeIsom(BinTree BT1,BinTree BT2,Position root1,Position root2)
{
    if (BT1[root1].Left+BT1[root1].Right!=BT2[root2].Left+BT2[root2].Right)
    {
       printf("No\n");
       return;
    }
    Position Left1=BT1[root1].Left,Right1=BT1[root1].Right;
    Position Left2=BT2[root2].Left,Right2=BT2[root2].Right;

    if (Left1+Left2+Right1+Right2==NOINFO*4)

    if (Left1==Left2)
    {
        JudgeIsom(BT1,BT2,Left1,Left2);
        JudgeIsom(BT1,BT2,Right1,Right2);
    }

    else if (Left1==Right2)
    {
        JudgeIsom(BT1,BT2,Left1,Right2);
        JudgeIsom(BT1,BT2,Right1,Left2);
    }
}
