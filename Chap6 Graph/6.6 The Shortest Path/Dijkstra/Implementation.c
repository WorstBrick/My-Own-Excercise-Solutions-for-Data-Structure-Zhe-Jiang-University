#include "Interface.h"

Graph InitGraph(int Nv)
{
    Graph G=(Graph)malloc(sizeof(*G));
    G->Nv=Nv;
    G->Ne=0;
    G->AdjRelation=(AdjMar)malloc(Nv*sizeof(WeightType *));

    int i,j;
    for (i=0;i<Nv;i++)
        G->AdjRelation[i]=malloc(Nv*sizeof(WeightType));

    for (i=0;i<Nv;i++)
        for (j=0;j<Nv;j++)
            G->AdjRelation[i][j]=INFINITY;

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    G->AdjRelation[E->V1][E->V2]=E->Weight;
    G->AdjRelation[E->V2][E->V1]=E->Weight;
}

void BuildGraph(Graph G)
{
    if (!Ne)
        return;
    else
    {
        G->Ne=Ne;
        Edge E;
        int i;

        for (i=0;i<Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(G,E);
        }
    }
}

void FindMinDist(Graph G,int dist[],int collected[])
{
    Vertex MinV,V;
    int MinDist=INFINITY;

    for (V=0;V<G->Nv;V++)
    {
        if (collected[V]==false && dist[V]<MinDist)
        {
            MinDist=dist[V];
            MinV=V;
        }
    }

    if (MinDist<INFINITY)
        return MinV;
    else
        return ERROR;
}

bool Dijkstra(Graph G,int dist[],int path[],Vertex S)
{
    bool collected[G->Nv];
    Vertex V,W;

    for (V=0;V<G->Nv;V++)
    {
        dist[V]=G->AdjRelation[S][V];
        path[V]=-1;
        collected[V]=false;
    }

    dist[S]=0;
    collected[S]=true;

    while(1)
    {
        V=FindMinDist(G,dist,collected);
        if (V==ERROR)
            break;
        collected[V]=true;
        for (W=0;W<G->Nv;W++)
        {
            if (collected[W]==false && G->AdjRelation[V][W]<INFINITY)
            {
                if (G->AdjRelation[V][W]<0)
                    return false;
                if (dist[V]+G->AdjRelation[V][W]<dist[W])
                {
                    dist[W]=dist[V]+G->AdjRelation[V][W];
                    path[W]=V;
                }
            }
        }
    }

    return true;
}

//求无权图的最短路径
void UnWeighted(Graph G,int dist[],int path[],Vertex S)
{
    dist[S]=0;
    Vertex V,W;
    for (V=0;V<G->Nv;V++)
        dist[V]=G->AdjRelation[S][V];

    Queue Q=CreateQueue(G->Nv);
    AddQ(Q,S);

    while (IsEmpty(Q))
    {
        V=DeleteQ(Q);
        for (W=0;W<G->Nv;W++)
        {
            if (G->AdjRelation[V][W]!=INFINITY && dist[V]+1<dist[W])
            {
                dist[W]=dist[V]+1;
                path[W]=V;
                AddQ(W);
            }
        }
    }
}
