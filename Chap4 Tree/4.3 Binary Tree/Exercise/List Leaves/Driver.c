#include "Interface.h"

int main(void)
{
    int quant;
    Node root;
    BinTree BT;

    scanf("%d",&quant);
    BT=InitTree(quant);
    root=FillTNode(BT,quant);
    printf("%d\n",root);
    ListLeaves(BT,quant,root);

    return 0;
}
