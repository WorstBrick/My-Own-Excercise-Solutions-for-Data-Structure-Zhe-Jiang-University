#include "interface.h"
#include <stdlib.h>
EleType FindKth(EleType * list,int n,int K)
{
    EleType judge=list[0];
    EleType * big=(EleType *)malloc(n-1);
    EleType * small=(EleType *)malloc(n-1);
    int Qb=0,Qs=0;
    int i;
    EleType temp;

    for (i=1;i<n;i++)
    {
        if ((temp=list[i])>judge)
        {
            big[Qb]=temp;
            Qb++;
        }
        else
        {
            small[Qs]=temp;
            Qs++;
        }
    }
    if (Qb>K-1)
        return FindKth(big,Qb,(Qb/2)+1);
    else if (Qb==K-1)
        return judge;
    else
        return FindKth(small,Qs,K-Qb-1);
}
