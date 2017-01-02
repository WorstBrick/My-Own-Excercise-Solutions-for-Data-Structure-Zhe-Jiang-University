#include "Interface.h"

int NextPrime(int TableSize)
{
    TableSize=(TableSize%2==0? TableSize+1:TableSize);
    int i;

    while (1)
    {
        for (i=(int)sqrt(TableSize);i>2 && TableSize&i!=0;i--)
            continue;
        if (i==2)
            break;
        else
            TableSize+=2;
    }

    return TableSize;
}

HashTable InitHashTable(int TableSize)
{
    HashTable H=(HashTable)malloc(sizeof(struct HTNode));
    H->TableSize=NextPrime(TableSize);
    H->AllKey=(KeyStorage)malloc((H->TableSize)*sizeof(struct KNode));
    int i

    for (i=0;i<H->TableSize;i++)
        H->AllKey[i].Flag=UnUsed;

    return H;
}

Position Hash(ElementType Key,HashTable H)
{
    return (Key%(H->TableSize));
}

bool Insert(ElementType Key,HashTable H)
{
    Position Address=FindLinear(Key,H);

    if (H->AllKey[Address].Flag==UnUsed)
    {
        H->AllKey[Address].Data=Key;
        H->AllKey[Address].Flag=IsUsed;
        return true;
    }
    else//说明Key已经存在与散列表里了,无需插入
        return false;
}

//线性探测法的Find()操作
Position FindLinear(ElementType Key,HashTable H)
{
    Position PrimaryAddress=Hash(Key,H);
    Position Address=PrimaryAddress;
    int D=0;

    while (H->AllKey[Address].Flag!=UnUsed && H->AllKey[Address]!=Key)//当找到一个"空位"或者发现Key已在表中就停止查找
    {
        D++;
        Address=(PrimaryAddress+D)%H->TableSize
    }

    return Address;//返回的Address要么是UnUsed的(即关键词Key还未被插入散列表中),要么就是Key的地址
}

Position FindQuadratic(ElementType Key,HashTable H)
{
    Position PrimaryAddress=Hash(Key,H);
    Position Address=PrimaryAddress;
    int i=0,D=0;

    while (H->AllKey[Address].Flag!=UnUsed && H->AllKey[Address]!=Key)
    {
        i++;
        if (i%2!=0)//发生奇数次冲突时,增量就为i*i
        {
            D=i*i;
            Address=(PrimaryAddress+D)%H->TableSize;
        }
        else//发生偶数次冲突时,增量为-((i-1)/2)^2,即-i*i/4
        {
            D=i*i/4;
            Address=PrimaryAddress-D;
            while (Address<0)
                Address+=H->TableSize;
        }
    }

    return Address;
}

bool Delete(ElementType Key,HashTable H)
{
    Position Address=FindLinear(Key,H);

    if (H->AllKey[Address].Flag==UnUsed)//说明Key并不存在于散列表中,无需删除
        return false;
    else
    {
        H->AllKey[Address].Flag=Deleted;
        return true;
    }
}
