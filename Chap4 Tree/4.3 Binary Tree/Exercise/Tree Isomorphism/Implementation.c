#include "Interface.h"

static void FillTNode(BinTree BT,int quant)
{
    int i;
    ElementType Data;
    Position Left,Right;

    for (i=0;i<quant;i++)
    {
        scanf("%c %d %d",&Data,&Left,&Right);
        (BT[i]).Data=Data;
        if (Left=='-')
            Left=NOINFO;
        if (Right=='-')
            Right=NOINFO;
        (BT[i]).Left=Left;
        (BT[i]).Right=Right;
    }
}


BinTree CreateTree(int quant)
{
    BinTree BT=(BinTree)malloc(quant*sizeof(*BT));
    FillTNode(BT,quant);

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

void JudgeIsom(BinTree BT1,BinTree BT2,int quant1,int quant2)
{
    if (quant1 != quant2)
    {
        printf("No\n");
        return;
    }

    int i,j,sons,flag=1;

    for (i=0;i<quant1;i++)
    {
        if ((j=Find(BT2,quant2,(BT1[i]).Data))==NOTFOUND)
        {
            printf("No\n");
            flag=0;
            break;
        }
        sons=(BT1[i]).Left+(BT1[i]).Right;
        if (sons!=(BT2[j]).Left+(BT2[j]).Right)
        {
            printf("No\n");
            flag=0;
            break;
        }
    }
    if (flag)
        printf("Yes\n");
}
