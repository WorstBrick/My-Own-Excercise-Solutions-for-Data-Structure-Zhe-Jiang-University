#include "Interface.h"

int main(void)
{
    int MaxSize;
    Position Ancestor,i,j;
    scanf("%d",&MaxSize);

    BTree BT=InitBTree(MaxSize);
    Insert(BT);
    scanf("%d %d",&i,&j);
    if (!BT[i])
        printf("ERROR: T[%d] is NULL\n",i);
    else if (!BT[j])
        printf("ERROR: T[%d] is NULL\n",j);
    else
    {
        Ancestor=CommonAncestor(i,j);
        printf("%d %d\n",Ancestor,BT[Ancestor]);
    }
    return 0;
}
