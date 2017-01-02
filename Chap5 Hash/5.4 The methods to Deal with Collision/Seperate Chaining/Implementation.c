#include "Interface.h"

int NextPrime(int TableSize)
{
    int Prime=(TableSize%2==0? TableSize+1:TableSize);
    int i;
    bool flag=true;

    while (flag)
    {
        for (i=(int)sqrt(Prime),flag=false;i>2;i--)
        {
            if (Prime%i==0)
            {
                flag=true;
                Prime+=2;
                break;
            }
        }
    }

    return Prime;
}

HashTable InitHashTable(int TableSize)
{
    HashTable H=(HashTable)malloc(sizeof(struct HTNode));
    H->TableSize=NextPrime(TableSize);
    H->AllKey=(AddressSpace)malloc((H->TableSize)*sizeof(struct ANode));
    int i;
    for (i=0;i<H->TableSize;i++)
    {
        H->AllKey[i].SynKeyHead=(KeyList)malloc(sizeof(struct KNode));
        H->AllKey[i].SynKeyHead->Next=NULL;
    }

    return H;
}

PtrToKNode Hash(ElementType Key,HashTable H)
{
    return (Key%H->TableSize);
}

Position Find(ElementType Key,HashTable H)
{
    Position Primary=Hash(Key,H);
    KeyList T=H->AllKey[Primary].SynKeyHead->Next

    while (T && T->Data!=Key)
        T=T->Next;

    return T;
}

bool Insert(ElementType Key,HashTable H)
{
    Position Primary=Hash(Key,H);
    KeyList T=Find(Key,H);

    if (T==NULL)
    {
        T=(PtrToKNode)malloc(sizeof(struct KNode));
        T->Data=Key;
        T->Next=H->AllKey[Primary].SynKeyHead->Next;
        H->AllKey[Primary].SynKeyHead->Next=T;
        return true;
    }
    else
        return false;
}

bool Delete(ElementType Key,HashTable H)
{
    Position Primary=Hash(Key,H);
    KeyList T=H->AllKey[Primary].SynKeyHead;

    while (T->Next && T->Next->Data!=Key)
        T=T->Next;
    if (T->Next==NULL)
        return false;
    else
    {
        PtrToKNode tmp=T->Next;
        T->Next=tmp->Next;
        free(tmp);
        return true;
    }
/*
    没有头结点的版本,就比较啰嗦了
    if (T && T->Data==Key)//当要删除的元素就在头上时
    {
        H->AllKey[Primary].SynKey=T->Next;
        free(T);
        return true;
    }

    while (T && T->Next && T->Next->Data!=Key)
        T=T->Next;
    if (T->Next==NULL)
        return false;
    else
    {
        PtrToKNode Tmp=T->Next;
        T->Next=Tmp->Next;
        free(Tmp);
        return true;
    }
*/
}
