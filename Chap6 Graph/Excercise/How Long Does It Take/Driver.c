#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    scanf("%d %d",&Nv,&Ne);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    WeightType * Earliest=(WeightType *)malloc(Nv*sizeof(WeightType));
    if (FindEarliestTime(G,Earliest))
        printf("%d",FindMax(G,Earliest));
    else
        puts("Impossible");

    return 0;
}
