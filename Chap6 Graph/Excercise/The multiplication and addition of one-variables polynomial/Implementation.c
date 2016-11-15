#include "Interface.h"


static Item NewNode(void)
{
    Item Tmp=(Item)malloc(sizeof(*Tmp));
    scanf("%d %d",&Tmp->Coe,&Tmp->Expo);
    Tmp->Next=NULL;

    return Tmp;
}


Poly CreatePoly(int Size)
{
    Poly P=(Poly)malloc(sizeof(*P));
    P->FirstItem=NewNode();
    Item Tmp=P->FirstItem;
    int i;

    for (i=1;i<Size;i++)
    {
        Tmp->Next=NewNode();
        Tmp=Tmp->Next;
    }

    return P;
}

static Item EasyNewNode(void)
{
    Item T=malloc(sizeof(*T));

    return T;
}

Poly Addition(Poly P1,Poly P2)
{
    Item T1=P1->FirstItem,T2=P2->FirstItem;/*我的多项式用带头节点的链表表示*/
    Poly Result=(Poly)malloc(sizeof(*Result));
    Item Tmp=Result->FirstItem=EasyNewNode();//EasyNewNode()是我的私有函数,创建一个空的多项式的项(就是什么数据都没的链表结点)

    while (T1 && T2)//这个循环的思路是先向空节点写入数据,再创建下一个空节点,
    {               //但会有一个问题,就是循环结束时,会在链表结尾多创建一个空的垃圾节点
        if (T1->Expo > T2->Expo)//T1与T2指向的结点在条件语句中更新
        {
            Tmp->Coe=T1->Coe;
            Tmp->Expo=T1->Expo;
            T1=T1->Next;
        }
        else if (T1->Expo < T2->Expo)
        {
            Tmp->Coe=T2->Coe;
            Tmp->Expo=T2->Expo;
            T2=T2->Next;
        }
        else
        {
            Tmp->Coe=T1->Coe+T2->Coe;
            Tmp->Expo=T1->Expo;
            T1=T1->Next;
            T2=T2->Next;
        }
        Tmp->Next=EasyNewNode();//并创建Tmp->Next,一个空结点
        if (T1 || T2)//当更新过后的T1与T2(即原T1,T2的Next)有不为空的时候,就把Tmp更新为Tmp->Next,这是为了后面的两个while循环做准备
            Tmp=Tmp->Next;
        else
            Tmp->Next=NULL;//否则,说明两个多项式都已经被读完了,就令Tmp->Next=NULL
    }

    while (T1)
    {
        Tmp->Coe=T1->Coe;
        Tmp->Expo=T1->Expo;
        if (T1->Next)
        {
            Tmp->Next=NewNode();
            Tmp=Tmp->Next;
        }
        else
            Tmp->Next=NULL;
        T1=T1->Next;
    }
    while (T2)
    {
        Tmp->Coe=T2->Coe;
        Tmp->Expo=T2->Expo;
        if (T2->Next)
        {
            Tmp->Next=NewNode();
            Tmp=Tmp->Next;
        }
        else
            Tmp->Next=NULL;
        T2=T2->Next;
    }

    return Result;
}

Poly Multiplication(Poly P1,Poly P2)
{
    Item Tmp,T1=P1->FirstItem,T2=P2->FirstItem;
    if (T1->Expo < T2->Expo)
    {
        Tmp=T1;
        T1=T2;
        T2=Tmp;
    }
    Poly Result=(Poly)malloc(sizeof(*Result));
    Tmp=Result->FirstItem=EasyNewNode();
    Tmp->Coe=(T1->Coe)*(T2->Coe);
    Tmp->Expo=T1->Expo+T2->Expo;
    T1=T1->Next;
    int MulExpo;
    Item LaterHandle[100];
    int Index=0;

    while (T1)
    {
        while (T2)
        {
            if ((MulExpo=T1->Expo+T2->Expo)>Tmp->Expo)
            {
                LaterHandle[Index]=EasyNewNode();
                LaterHandle[Index]->Coe=(T1->Coe)*(T2->Coe);
                LaterHandle[Index]->Expo=MulExpo;
                Index++;
            }
            else if (MulExpo==Tmp->Expo)
                Tmp->Coe+=(T1->Coe)*(T2->Coe);
            else
            {
                Tmp->Next=EasyNewNode();
                Tmp=Tmp->Next;
                Tmp->Coe=(T1->Coe)*(T2->Coe);
                Tmp->Expo=MulExpo;
            }
            T2=T2->Next;
        }
        T1=T1->Next;
        T2=P2->FirstItem;
    }
    Tmp->Next=NULL;
    if (!Index)
        return Result;
    else
    {
        Tmp=Result->FirstItem;
        int i;
        for (i=0;Tmp && i<=Index;Tmp=Tmp->Next)
        {
            if (Tmp->Expo==LaterHandle[i]->Expo)
            {
                Tmp->Coe+=LaterHandle[i]->Coe;
                i++;
            }
            else if (Tmp->Next && LaterHandle[i]->Expo > Tmp->Next->Expo && LaterHandle[i]->Expo<Tmp->Expo)
            {
                LaterHandle[i]->Next=Tmp->Next;
                Tmp->Next=LaterHandle[i];
                i++;
            }
        }

        //free(LaterHandle);
        return Result;
    }
}

void ShowPoly(Poly P)
{
    Item Tmp=P->FirstItem;

    while (Tmp)
    {
        printf("%d %d",Tmp->Coe,Tmp->Expo);
        if (Tmp->Next)
            printf(" ");
        Tmp=Tmp->Next;
    }
}
