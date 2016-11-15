#include "Interface.h"

static void attach(int,int,PtrToPNode *);


Poly creatPoly(int quant)
{
    P=(Poly)malloc(sizeof(*P));
    int num,coe,expon;
    Poly tmp,tmpHead;

    for (num=0,tmpHead=P;num<quant;num++,tmpHead=tmp) //复杂度为O(quant)
    {
        tmp=(PtrToPNode)malloc(sizeof(*tmp));
        tmpHead->next=tmp;
        scanf("%d",&coe);
        scanf("%d",&expon);
        tmp->coe=coe;
        tmp->expon=expon;
    }
    tmpHead->next=NULL;

    return P;
}

Poly add(Poly P1,Poly P2)
{
    Poly result=(Poly)malloc(sizeof(*result));
    PtrToPNode rear=result;
    PtrToPNode tmp1=P1->next,tmp2=P2->next;
    int SumCoe;

    while (tmp1 && tmp2)
    {
        if (tmp1->expon > tmp2->expon)
        {
            attach(tmp1->coe,tmp1->expon,&rear);
            tmp1=tmp1->next;
        }
        else if (tmp1->expon < tmp2->expon)
        {
            attach(tmp2->coe,tmp2->expon,&rear);
            tmp2=tmp2->next;
        }
        else
        {
            if ((SumCoe=tmp1->coe + tmp2->coe))
            {
                attach(SumCoe,tmp1->expon,&rear);
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
        }
    }
    for (;tmp1;tmp1=tmp1->next)
        attach(tmp1->coe,tmp1->expon,&rear);
    for (;tmp2;tmp2=tmp2->next)
        attach(tmp2->coe,tmp2->expon,&rear);

    free(P1);
    free(P2);

    return result;
}

static void attach(int coe,int expon,PtrToPNode * PtrRear)//这个"指针的指针"是局部变量,但他指向的对象却是外部的
{
    PtrToPNode tmp=(PtrToPNode)malloc(sizeof *tmp);
    tmp->next=NULL;
    /*(*rear)->next=tmp;*/
    tmp->coe=coe;
    tmp->expon=expon;
    (*PtrRear)->next=tmp;
    *PtrRear=tmp;
}

MulPoly * mul(Poly P1,Poly P2)
{
    MulPoly * result=(MulPoly *)malloc(sizeof *result);
    Poly tmp1=P1->next;
    Poly tmp2=P2->next;
    int quant=tmp1->expon+tmp2->expon+1;
    result->poly=(int *)malloc(quant*sizeof(int));
    result->quant=quant;
    int i,coe,expon;

    for (i=0;i<quant;i++)
        (result->poly)[i]=0;
    while (tmp1)
    {
        while(tmp2)
        {
            expon=tmp1->expon+tmp2->expon;
            coe=(tmp1->coe)*(tmp2->coe);
            (result->poly)[expon]+=coe;
            tmp2=tmp2->next;
        }
        tmp1=tmp1->next;
        tmp2=P2->next;
    }

    return result;
}

void ShowAdd(Poly P)
{
    Poly tmp=P->next;
    while (tmp)
    {
        printf("%d ",tmp->coe);
        printf("%d ",tmp->expon);
        tmp=tmp->next;
    }
    free(P);
}

void ShowMul(MulPoly * P)
{
    int i;
    int quant=P->quant;
    int * poly=P->poly;

    for (i=quant-1;i>=0;i--)
    {
        if (poly[i])
        {
            printf("%d",poly[i]);
            printf("%d",i);
        }
    }
    printf("\n");
    free(P->poly);
    free(P);
}
