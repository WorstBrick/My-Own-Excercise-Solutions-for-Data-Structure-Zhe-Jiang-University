#include "Interface.h"
#include <stdio.h>

bool * Visited;

MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    int i;
    MGraph G=(MGraph)malloc(sizeof(*G));
    G->Ne=0;
    G->Nv=VertexNum;

    G->AdjRelation=(AdjMar)malloc(VertexNum*sizeof(WeightType*));
    for (i=0;i<VertexNum;i++)
        G->AdjRelation[i]=(WeightType*)malloc(VertexNum*sizeof(WeightType));

    for (V=0;V<VertexNum;V++)
        for (W=0;W<VertexNum;W++)
            G->AdjRelation[V][W]=INFINITY;

    return G;
}


void InsertEdge(MGraph Graph,Edge E)
{
    Graph->G[E->V1][E->V2]=E->Weight;
    Graph->G[E->V2][E->V1]=E->Weight;
}


MGraph BuildGraph(void)
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);

    scanf("%d",&(Graph->Ne));
    if (Graph->Ne!=0)
    {
        E=(Edge)malloc(sizeof(*E));
        for (i=0;i<Graph->Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }


    return Graph;
}


bool IsEdge(MGraph Graph,Vertex V,Vertex W)
{
    return Graph->G[V][W]<INFINITY? true:false;
}

void DFS(MGraph G,Vertex S)
{
    Vertex V;
    Visited[S]=true;
    for (V=0;V<G->Nv;V++)
    {
        if (IsEdge(G,S,V))
            if (!Visited[V])
                DFS(G,V);
    }
}

void BFS(MGraph G,Vertex S)
{
    Queue Q=CreateQueue(G->Nv);
    Vertex V;
    AddQ(S);
    Visited[S]=true;

    while (!IsEmpty(Q))
    {
        S=DeleteQ(Q);
        Visited[S]=true;
        for (V=0;V<G->Nv;V++)
        {
            if (IsEdge(G,S,V))
                if (!Visited[V])
                    AddQ(Q,V);
        }
    }
}
