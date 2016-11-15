#include "Interface.h"


int main(void)
{
    int quant1,quant2;
    BinTree BT1,BT2;

    scanf("%d",&quant1);
    BT1=CreateTree(quant1);

    scanf("%d",&quant2);
    BT2=CreateTree(quant2);

    JudgeIsom(BT1,BT2,quant1,quant2);

    return 0;
}
