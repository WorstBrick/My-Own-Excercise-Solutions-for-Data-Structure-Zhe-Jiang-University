#include "interface.h"

int Length(List L)
{
    int cnt=0;
    PtrToLNode temp=L;

    while (temp)
    {
        cnt++;
        temp=temp->Next;
    }

    return cnt;
}

ElementType FindKth(List L,int K)
{
    int cnt=1;
    Position temp=L;

    while (cnt!=K && temp)
    {
        temp=temp->Next;
        cnt++
    }

    if ((cnt==k)&& temp)
        return temp->Data;
    else
        return ERROR;
}

Position Find(List L,ElemenType X)
{
    Position temp=L;

    while (temp && temp->Data!=X)
        temp=temp->Next;

    return temp;
}

List Insert_vCasual(List L,ElemenType X,int i)
{
    List temp=(PtrToLNode)malloc(sizeof *temp);
    temp->Data=X;

    if (i==1)
    {
        temp->Next=L;
        return temp;
    }
    else
    {
        Position pt=L;
        int cnt=1;
        while (pt && cnt<i-1)
        {
            cnt++;
            pt=pt->Next;
        }
        if (cnt==i-1)
        {
            temp->Next=pt->Next;
            pt->Next=temp;
            return L;
        }
        printf("Illegal position %d\n",i);
        return pt;
    }
}

bool Insert(List L,ElemenType X,int i)
{
    Position temp,pt=L;
    int cnt=0;

    while (pt && cnt!=i-1)
    {
        cnt++
        pt=pt->Next;
    }
    if (cnt==i-1)
    {
        temp=malloc(sizeof *temp);
        temp->Data=X;
        temp->Next=pt->Next;
        pt->Next=temp;
        return true;
    }
    printf("Illegal position %d\n",i);
    return false;
}


bool Delete(List L,int i)
{
    int cnt=0;
    Position temp;
    Position pt;

    while (pt && cnt<i-1)
    {
        pt=pt->Next;
        cnt++;
    }
    if (cnt==i-1)
    {
        temp=pt->Next;
        pt->Next=temp->Next;
        free(temp);
        return true;
    }
    printf("Illegal position %d\n",i);
    return false;
}
