#include "Interface.h"

int main(void)
{
    int TableSize,N,i;
    scanf("%d %d",&TableSize,&N);

    HashTable H=InitHashTable(TableSize);
    ElementType Key;

    for (i=0;i<N;i++)
    {
        scanf("%d",&Key);
        InsertModifed(Key,H);
    }

    return 0;
}
