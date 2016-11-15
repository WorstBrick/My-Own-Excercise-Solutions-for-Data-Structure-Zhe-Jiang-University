#include "Interface.h"

int main(void)
{
    int Size1,Size2;

    scanf("%d",&Size1);
    Poly P1=CreatePoly(Size1);
    scanf("%d",&Size2);
    Poly P2=CreatePoly(Size2);

    //Poly MulResult=Multiplication(P1,P2);
    //ShowPoly(MulResult);
    Poly AddResult=Addition(P1,P2);
    ShowPoly(AddResult);

    return 0;
}
