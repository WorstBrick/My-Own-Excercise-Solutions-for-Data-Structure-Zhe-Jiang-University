#include "Interface.h"
#include <stdlib.h>
ATree InitTree(ElementType Data)
{
    ATree AT=(ATree)malloc(sizeof(*AT));
    AT->Data=Data;
    AT->Left=AT->Right=NULL;

    return AT;
}

int GetHeight(ATree AT)
{
    if (!AT)
        return 0;
    else
    {
        int LSonHeight=GetHeight(AT->Left);
        int RSonHeight=GetHeight(AT->Right);

        return ((LSonHeight>=RSonHeight? LSonHeight : RSonHeight)+1);
    }
}

ATree RRrotation(ATree AT)
{
    ATree Tmp=AT->Right;
    AT->Right=Tmp->Left;
    Tmp->Left=AT;

    return Tmp;
}

ATree LLrotation(ATree AT)
{
    ATree Tmp=AT->Left;
    AT->Left=Tmp->Right;
    Tmp->Right=AT;

    return Tmp;
}

ATree RLrotation(ATree AT)
{
    AT->Right=LLrotation(AT->Right);
    AT=RRrotation(AT);

    return AT;
}

ATree LRrotation(ATree AT)
{
    AT->Left=RRrotation(AT->Left);
    AT=LLrotation(AT);

    return AT;
}

ATree Insert(ATree AT,ElementType Data)
{
    if (!AT)
    {
        AT=InitTree(Data);
        return AT;
    }
    else
    {
        if (Data<AT->Data)
            AT->Left=Insert(AT->Left,Data);/*开始的时候我把这里的赋值语句写成了AT=Insert(AT->Left,Data);
        else                                答案自然是错的*/
            AT->Right=Insert(AT->Right,Data);
        int BalanceFactor=GetHeight(AT->Left)-GetHeight(AT->Right);
        if (BalanceFactor==-2)
        {
            if ((GetHeight(AT->Right->Left)-GetHeight(AT->Right->Right))==-1)
                AT=RRrotation(AT);
            else if ((GetHeight(AT->Right->Left)-GetHeight(AT->Right->Right))==1)
                AT=RLrotation(AT);
        }
        else if (BalanceFactor==2)
        {
            if ((GetHeight(AT->Left->Left)-GetHeight(AT->Left->Right))==-1)
                AT=LRrotation(AT);
            else if ((GetHeight(AT->Left->Left)-GetHeight(AT->Left->Right))==1)
                AT=LLrotation(AT);
        }
        return AT;
    }
}
