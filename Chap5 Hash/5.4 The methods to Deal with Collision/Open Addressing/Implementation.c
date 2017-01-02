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
    else//˵��Key�Ѿ�������ɢ�б�����,�������
        return false;
}

//����̽�ⷨ��Find()����
Position FindLinear(ElementType Key,HashTable H)
{
    Position PrimaryAddress=Hash(Key,H);
    Position Address=PrimaryAddress;
    int D=0;

    while (H->AllKey[Address].Flag!=UnUsed && H->AllKey[Address]!=Key)//���ҵ�һ��"��λ"���߷���Key���ڱ��о�ֹͣ����
    {
        D++;
        Address=(PrimaryAddress+D)%H->TableSize
    }

    return Address;//���ص�AddressҪô��UnUsed��(���ؼ���Key��δ������ɢ�б���),Ҫô����Key�ĵ�ַ
}

Position FindQuadratic(ElementType Key,HashTable H)
{
    Position PrimaryAddress=Hash(Key,H);
    Position Address=PrimaryAddress;
    int i=0,D=0;

    while (H->AllKey[Address].Flag!=UnUsed && H->AllKey[Address]!=Key)
    {
        i++;
        if (i%2!=0)//���������γ�ͻʱ,������Ϊi*i
        {
            D=i*i;
            Address=(PrimaryAddress+D)%H->TableSize;
        }
        else//����ż���γ�ͻʱ,����Ϊ-((i-1)/2)^2,��-i*i/4
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

    if (H->AllKey[Address].Flag==UnUsed)//˵��Key����������ɢ�б���,����ɾ��
        return false;
    else
    {
        H->AllKey[Address].Flag=Deleted;
        return true;
    }
}
