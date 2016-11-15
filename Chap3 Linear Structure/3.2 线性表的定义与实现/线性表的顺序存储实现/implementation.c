#include "definition.h"

List MakeEmpty(void)
{
    List L;
    L=(List)malloc(sizeof *L);
    L->Last=-1;

    return L;
}

Position Find(List L,ElemenType X)
{
    Position i;
    ElemenType * ep=L->Data;
    Position last=L->Last;

    for (i=0;ep[i]==X && i<=last;i++);

    if (i>last)
        return ERROR;
    else
        return i;
}

bool Insert(List L,ElemenType X,Position i)
{
    if (L->Last==MAXSIZE-1)
    {
        printf("The list is fully.\n")
        return false;
    }

    if (i<1 || i>L->Last+2)
    {
        printf("The position is illegal.\n");
        return false;
    }

    Position Move=L->Last;
    ElemenType * ept=L->Data;

    for (;Move>=i-1;Move--)
        ept[Move]=ept[Move-1];

    ept[Move]=X;
    L->Last++;

    return true;
}

bool Delete(List L,Position i)
{
    Position j;

    if (i<1 || i>L->Last+1)
    {
        printf("Position %d is illeagal\n",i);
        return false;
    }

    for (j=i;j<L->Last;j++)
        L->Data[j-1]=L->Data[j];

    L->Last--;

    return true;
}
