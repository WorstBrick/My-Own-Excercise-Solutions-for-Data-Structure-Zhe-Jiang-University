#include "Definition.h"

int Compare(int e1,inte2)
{
    if (e1>e2)
        return 1;
    else if (e1<e2)
        return -1;
    else
        return 0;
}

void Attach(int coef,int expon,Polynomial * PtrRear)
{
    Polynomial P;

    P=(Polynomial)malloc(sizeof *P);
    P->coef=coef;
    P->expon=expon;
    P->next=NULL;

    (*PtrRear)->next=P;
    *PtrRear=P
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial Front,Rear,Temp;
    int sum;

    Rear=(Polynomial)malloc(sizeof * Rear);
    Front=Rear;
    while (P1 && P2)
        switch(Compare(P1->expon,P2->expon))
        {
            case 1:
                Attach(P1->coef,P1->expon,&Rear);
                P1=P1->next;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&Rear);
                P2=P2->next;
                break;
            case 0:
                sum=P1->coef+P2->coef;
                if (sum)
                    Attach(sum,P1->expon,&Rear);
                P1=P1->next;
                P2=P2->next;
                break;
        }
    for (;P1;P1=P1->next)
        Attach(P1->coef,P1->expon,&Rear);
    for (;P2;P2=P2->next)
        Attach(P2->coef,P2->expon,&Rear);

    Rear->next=NULL;
    Temp=Front;
    Front=Front->next;

    free(Temp);

    return Front;
}
