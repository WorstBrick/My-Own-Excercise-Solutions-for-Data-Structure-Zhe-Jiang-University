#include "Interface.h"


Vertex FindMin(Graph G,int dist[],bool collected[])
{
    Vertex MinVer,V;
    int MinDist=INFINITY;

    for (V=0;V<G->Nv;V++)
    {
        if (dist[V]<MinDist && !collected[V])
        {
            MinDist=dist[V];
            MinVer=V;
        }
    }

    if (MinDist==INFINITY)
        return ERROR;
    else
        return MinVer;
}



bool Dijkstra(Graph G,Vertex S,int dist[],Vertex path[],bool collected[])
{
    //假设dist,path并没有被初始化
    Vertex W;
    for (W=0;W<G->Nv;W++)
        dist[W]=INFINITY;
    AdjList Tmp=G->AllVer[S]->FirstEdge;
    while (Tmp)
    {
        dist[Tmp->V]=Tmp->Weight;
        Tmp=Tmp->Next;
    }

    for (W=0;W<G->Nv;W++)
        path[W]=-1;


    dist[S]=0;
    collected[S]=true;

    while (1)
    {
        if ((W=FindMin(G,dist,collected)==ERROR)
            break;
        collected[W]=true;
        Tmp=G->AllVer[W]->FirstEdge;
        while (Tmp)
        {
            if (!collected[Tmp->V] && dist[W]+Tmp->Weight<dist[Tmp->V])
            {
                if (Tmp->Weight<0)
                    return false;
                dist[Tmp->V]=dist[W]+Tmp->Weight;
                path[Tmp->V]=V;
            }
            Tmp=Tmp->Next;
        }
    }

    return true;
}
