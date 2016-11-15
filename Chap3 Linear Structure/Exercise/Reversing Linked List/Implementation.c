#include "Interface.h"

static List New(void)
{
    List Temp=(List)malloc(sizeof(*Temp));
    Temp->Next=NULL;

    return Temp;
}

List CreateList(int Quant)
{
    int i;
    ElementType Data;
    List L=New(),Temp=New();
    L->Next=Temp;

    for (i=0;i<Quant-1;i++)
    {
        scanf("%d",&Data);
        Temp->Data=Data;
        Temp->Next=New();
        Temp=Temp->Next;
    }
    scanf("%d",&Data);
    Temp->Data=Data;
    Temp->Next=NULL;

    return L;
}


List ReverseK(List L,int N,int K)
{
    int Flag=N-N%K,i=1;
    int j;
    List End,TemEnd,Temp,Second,Third,Prev;

    Temp=L;
    End=NULL;
    while (i<Flag+1)
    {
        Prev=NULL;
        for (j=1,TemEnd=Temp;j<=K;j+=2)
        {
            Second=Temp->Next;
            Third=Temp->Next->Next;
            Temp->Next=Prev;
            if (j!=K)
            {
                Second->Next=Temp;
                Prev=Second;
                Temp=Third;
            }
            else
            {
                Prev=Temp;
                Temp=Second;
                j++;
                break;
            }
        }
        i=i+j-1;
        if (!End)
        {
            End=L;
            L=Prev;
        }
        else
        {
            End->Next=Prev;
            End=TemEnd;
        }
    }

    if (i<N+1)
        End->Next=Temp;

    return L;
}

void ShowList(List T)
{
    //List T=L->Next;

    while (T)
    {
        printf("0x%p %d 0x%p\n",T,T->Data,T->Next);
        T=T->Next;
    }
}
