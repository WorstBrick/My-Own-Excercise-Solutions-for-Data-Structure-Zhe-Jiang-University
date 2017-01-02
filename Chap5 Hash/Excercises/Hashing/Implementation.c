#include "Interface.h"

bool Switch=true;

int NextPrime(int TableSize)
{
    int Prime=(TableSize%2==0? TableSize+1:TableSize+2);
    int i;

    while (true)
    {
        for (i=(int)sqrt(Prime);i>2 && i%Prime!=0;i--)
            continue;
        if (i==2)
            break;
        else
            Prime+=2;
    }

    return Prime;
}

HashTable InitHashTable(int TableSize)
{
    HashTable H=(HashTable)malloc(sizeof(*H));
    H->TableSize=NextPrime(TableSize);
    H->Cells=(StorageSpace)malloc((H->TableSize)*sizeof(struct KNode));
    int i;

    for (i=0;i<H->TableSize;i++)
        H->Cells[i].Flag=Empty;

    return H;
}

Position Hash(ElementType Key,HashTable H)
{
    return (Key%(H->TableSize));
}

Position Find(ElementType Key,HashTable H)
{
    Position Primary=Hash(Key,H);
    Position Current=Primary;
    int D=0;
    //bool flag1=false,flag2=false;
    int HalfSite=(H->TableSize)/2;

    while (H->Cells[Current].Flag!=Empty && H->Cells[Current].Data!=Key && D<=HalfSite)
    {
        /*if (Current==Primary && flag1 && !flag2)
            flag2=true;
        else if (Current==Primary && flag1 && flag2)
            break;*/
        D++;
        Current=(Primary+D*D)%(H->TableSize);
        //flag1=true;
    }

    /*if (Current==Primary && flag1 && flag2)
        return NOPLACE;*/
    if (D>HalfSite)
        return NOPLACE;
    else
        return Current;
}
static void ShowAddress(Position Address)
{
    if (Switch)
    {
        if (Address==NOPLACE)
            printf("-");
        else
            printf("%d",Address);
        Switch=false;
        return;
    }

    if (Address==NOPLACE)
        printf(" -");
    else
        printf(" %d",Address);
}

void InsertModifed(ElementType Key,HashTable H)
{
    Position Address=Find(Key,H);

    if (Address!=NOPLACE && H->Cells[Address].Flag==Empty)
    {
        H->Cells[Address].Flag=IsUsed;
        H->Cells[Address].Data=Key;
    }

    ShowAddress(Address);
}

