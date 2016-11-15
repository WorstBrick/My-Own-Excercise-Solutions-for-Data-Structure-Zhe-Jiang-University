#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    scanf("%d %d",&Nv,&Ne);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);
    Vertex EndVer,W;
    WeightType * Earliest=(WeightType *)malloc(Nv*sizeof(WeightType));
    WeightType * Latest=(WeightType *)malloc(Nv*sizeof(WeightType));

    if ((EndVer=CalEarliestTime(G,Earliest))==ERROR)
        puts("0");
    else
    {
        printf("%d\n",Earliest[EndVer]);
        for (W=0;W<Nv;W++)
        {
            if (G->AllVer[W].FirstEdge==NULL)
                Latest[W]=Earliest[W];
            else
                Latest[W]=INFINITY;
        }
        Latest[0]=CalLatestTime(G,0,Latest);

        for (W=0;W<Nv;W++)
        {
           if (G->AllVer[W].InDegree2==0)
                FindKeyActivities(G,W,Earliest,Latest);
        }
    }

    return 0;
}
