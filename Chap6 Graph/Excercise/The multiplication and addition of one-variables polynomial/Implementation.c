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
    Item T1=P1->FirstItem,T2=P2->FirstItem;/*�ҵĶ���ʽ�ô�ͷ�ڵ�������ʾ*/
    Poly Result=(Poly)malloc(sizeof(*Result));
    Item Tmp=Result->FirstItem=EasyNewNode();//EasyNewNode()���ҵ�˽�к���,����һ���յĶ���ʽ����(����ʲô���ݶ�û��������)

    while (T1 && T2)//���ѭ����˼·������սڵ�д������,�ٴ�����һ���սڵ�,
    {               //������һ������,����ѭ������ʱ,���������β�ഴ��һ���յ������ڵ�
        if (T1->Expo > T2->Expo)//T1��T2ָ��Ľ������������и���
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
        Tmp->Next=EasyNewNode();//������Tmp->Next,һ���ս��
        if (T1 || T2)//�����¹����T1��T2(��ԭT1,T2��Next)�в�Ϊ�յ�ʱ��,�Ͱ�Tmp����ΪTmp->Next,����Ϊ�˺��������whileѭ����׼��
            Tmp=Tmp->Next;
        else
            Tmp->Next=NULL;//����,˵����������ʽ���Ѿ���������,����Tmp->Next=NULL
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
