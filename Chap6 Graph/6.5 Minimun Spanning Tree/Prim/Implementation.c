#include "Interface.h"

/*只实现Prim算法.
图的一般性操作(例如创建图之类的)不在此实现*/
int Prim(MGraph G,LGraph MST)
{
    WeightType * dist=(WeightType *)malloc((G->Nv)*sizeof(WeightType));
    WeightType TotalWeight=0;
    Vertex * parent=(Vertex *)malloc((G->Nv)*sizeof(Vertex));
    Vertex V,W;
    int VCount=0;
    Edge E=(Edge)malloc(sizeof(*E));

    for (V=0;V<G->Nv;V++)
    {
        dist[V]=G->AdjRelation[0][V];
        parent[V]=0;
    }


    MST=InitLGraph(G->Nv);
    dist[0]=0;
    VCount++;
    parent[0]=-1;

    while (1)
    {
        V=FindMinDist(G,dist);
        if (V==ERROR)
            break;
        E->V1=parent[V];
        E->V2=V;
        E->Weight=dist[V];
        InsertLGraphEdge(MST,E);
        TotalWeight+=dist[V];
        dist[V]=0;
        VCount++;

        for (W=0;W<G->Nv;W++)
        {
            if (dist[W]!=0 && G->G[V][W]<INFINITY)
            {
                if (G->AdjRelation[V][W]<dist[W])
                {
                    dist[W]=G->AdjRelation[V][W];
                    parent[W]=V;
                }
            }
        }
    }
    if (VCount<G->Nv)
        TotalWeight=ERROR;

    return TotalWeight;
}

Vertex FindMinDist(MGraph G,WeightType dist[])
{
    Vertex MinV,V;
    WeightType MinDist=INFINITY;

    for (V=0;V<G->Nv;V++)
    {
        if (dist[V]!=0 && dist[V]<MinDist)
        {
            MinDist=dist[V];
            MinV=V;
        }
    }

    if (MinDist<INFINITY)Vertex FindMinDist(MGraph G,WeightType dist[])
        return MinV;
    else
        return ERROR;
}
