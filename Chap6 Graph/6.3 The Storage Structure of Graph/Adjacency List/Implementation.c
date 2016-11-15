#include "Interface.h"

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph;

    Graph=(LGraph)malloc(sizeof(*Graph));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for (V=0;V<Graph->Nv;V++)
        Graph->G[V]=NULL;

    return Graph;
}


void InsertEdge(LGraph Graph,Edge E)
{
    //建立新的邻接点
    PtrToAdjVNode NewNode;
    NewNode=(PtrToAdjVNode)malloc(sizeof(*NewNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;

    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V1;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge=NewNode;
}

LGraph BuildGraph(void)
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);

    scanf("%d",&(Graph->Ne));
    if (!(Graph->Ne))
    {
        E=(Edge)malloc(sizeof(*E));
        for (i=0;i<Graph->Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }
    for (V=0;V<Graph->Nv;V++)
        scanf("%c",&(Graph->G.Data));

    return Graph;
}


void Visit(Vertex V)
{
    printf("Now visiting the vertex %d\n",V);
}


void DFS(LGraph Graph,Vertex V,void(*Visit)(Vertex))
{
    PtrToAdjVNode W;

    Visit(V);
    Visited[V]=true;

    for (W=Graph->G[V].FirstEdge;W;W=W->Next)
        if (!Visited[W->AdjV])
            DFS(Graph,W->AdjV,Visit);
}
