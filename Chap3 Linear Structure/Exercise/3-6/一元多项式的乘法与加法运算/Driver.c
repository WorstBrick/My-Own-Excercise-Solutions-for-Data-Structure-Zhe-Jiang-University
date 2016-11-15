#include "Interface.h"

int main(void)
{
    int NonZeroItem1,NonZeroItem2;
    Poly P1,P2;

    scanf("%d",&NonZeroItem1);
    P1=creatPoly(NonZeroItem1);
    scanf("%d",&NonZeroItem2);
    P2=creatPoly(NonZeroItem2);
    ShowMul(mul(P1,P2));
    ShowAdd(add(P1,P2));

    return 0;

}

