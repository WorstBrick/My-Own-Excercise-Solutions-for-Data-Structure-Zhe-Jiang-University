#include "Interface.h"

Graph InitGraph(int Nv)
{
    int i,j;
    Graph G=(Graph)malloc(sizeof(*G));
    G->Nv=Nv;
    G->Ne=0;
    G->AdjM=(WeightType**)malloc(Nv*sizeof(WeightType*));
    for (i=0;i<Nv;i++)
        G->AdjM[i]=(WeightType*)malloc(Nv*sizeof(WeightType));
    for (i=0;i<Nv;i++)
    {
        for (j=0;j<Nv;j++)
        {
            if (i==j)
                G->AdjM[i][j]=0;
            else
                G->AdjM[i][j]=INFINITY;
        }
    }

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    G->AdjM[E->V1-1][E->V2-1]=E->Weight;
    G->AdjM[E->V2-1][E->V1-1]=E->Weight;
}

void BuildGraph(Graph G,int Ne)
{
    if ((G->Ne=Ne)!=0)
    {
        int i;
        Edge E=(Edge)malloc(sizeof(*E));
        for (i=0;i<Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(G,E);
        }
    }
}


bool Floyd(Graph G)
{
    Vertex U,V,W;

    for (U=0;U<G->Nv;U++)
        for (V=0;V<G->Nv;V++)
            for (W=0;W<G->Nv;W++)
            {
                if (G->AdjM[V][U]+G->AdjM[U][W]<G->AdjM[V][W])
                {
                    if (G->AdjM[V][U]+G->AdjM[U][W]<0)
                        return false;
                    G->AdjM[V][W]=G->AdjM[V][U]+G->AdjM[U][W];
                }
            }


    return true;
}


bool EachSorceLongestPath(Graph G,WeightType * Distance)
{
    Vertex V,W,I;
    WeightType MaxPerLine;

    for (V=0,I=1;V<G->Nv;V++,I++)
    {
        for (W=0,MaxPerLine=G->AdjM[V][0];W<G->Nv;W++)
        {
            if (G->AdjM[V][W]==INFINITY)
                return false;
            else if (G->AdjM[V][W]>MaxPerLine)
                MaxPerLine=G->AdjM[V][W];
        }
        Distance[I]=MaxPerLine;
    }

    return true;
}

Vertex FindSuitableSorce(WeightType * Distance)
{
    Vertex SuitableSorce=1;
    WeightType MinPath=Distance[1];
    Vertex V;
    int Nv=Distance[0];

    for (V=2;V<Nv;V++)
    {
        if (Distance[V]<MinPath)
        {
            MinPath=Distance[V];
            SuitableSorce=V;
        }
    }

    return SuitableSorce;
}
