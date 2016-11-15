#include "Interface.h"


Graph InitGraph(int Nv)
{
    Graph G=(Graph)malloc(sizeof(*G));
    G->Ne=0;
    G->Nv=Nv;
    G->Allver=(VerList)malloc(Nv*sizeof(struct VNode));
    int i;

    for (i=0;i<Nv;i++)
        G->Allver[i].FirstEdge=NULL;

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=E->V2;
    NewNode->Length=E->Length;
    NewNode->Fare=E->Fare;
    NewNode->Next=G->Allver[E->V1].FirstEdge;
    G->Allver[E->V1].FirstEdge=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->V=E->V1;
    NewNode->Length=E->Length;
    NewNode->Fare=E->Fare;
    NewNode->Next=G->Allver[E->V2].FirstEdge;
    G->Allver[E->V2].FirstEdge=NewNode;

}

void BuildGraph(Graph G,int Ne)
{
    if (Ne!=0)
    {
        Edge E=(Edge)malloc(sizeof(*E));
        int i;

        for (i=0;i<Ne;i++)
        {
            scanf("%d %d %d %d",&E->V1,&E->V2,&E->Length,&E->Fare);
            InsertEdge(G,E);
        }
    }
}


Vertex FindBestVer(Graph G,WeightType dist[],bool collected[])
{
    Vertex BestVer=0,V;
    WeightType MinDist=INFINITY;

    for (V=0;V<G->Nv;V++)
    {
        if (!collected[V] && dist[V]<MinDist)
        {
            MinDist=dist[V];
            BestVer=V;
        }
    }

    if (MinDist==INFINITY)
        return ERROR;
    else
        return BestVer;
}


static WeightType * NewArray(int Nv)
{
    WeightType * New=(WeightType *)malloc(Nv*sizeof(WeightType));

    return New;
}


WeightType * Dijkstra(Graph G,Vertex S,Vertex * path)
{
    WeightType * dist=NewArray(G->Nv);
    bool * collected=(bool *)malloc((G->Nv)*sizeof(bool));
    Vertex W;

    for (W=0;W<G->Nv;W++)
    {
        dist[W]=INFINITY;
        collected[W]=false;
        path[W]=-1;
    }

    dist[S]=0;
    AdjList T=G->Allver[S].FirstEdge;
    while (T)
    {
        dist[T->V]=T->Length;//先把与源点S相邻的顶点到源点的距离收入dist中
        path[T->V]=S;//并在path中把这些与源点S相邻的顶点的"父节点"都设为S,为之后的处理做准备
        T=T->Next;
    }

    while (1)
    {
        W=FindBestVer(G,dist,collected);
        if (W==ERROR)
            break;
        collected[W]=true;
        T=G->Allver[W].FirstEdge;
        while (T)
        {
            if (T->Length+dist[W]==dist[T->V] && FindTotalFare(G,W,path)+T->Fare<FindTotalFare(G,T->V,path))
                path[T->V]=W;
            else if (T->Length+dist[W]<dist[T->V])
            {
                dist[T->V]=T->Length+dist[W];
                path[T->V]=W;
            }
            T=T->Next;
        }
    }

    return dist;
}


//用于计算目标终点D到源点S的路径上的总路费的函数
WeightType FindTotalFare(Graph G,Vertex D,Vertex * path)//复杂度为:设D到S路径上的定点数为|D|,每个顶点的平均邻接点数为K
{
    WeightType TotalFare=0;                             //所以复杂度为O(|D|*K)
    Vertex W,U;
    AdjList T;

    for (W=path[D],U=D;W!=-1;W=path[W])
    {
        T=G->Allver[W].FirstEdge;
        while (T && T->V!=U)
            T=T->Next;
        TotalFare+=T->Fare;
        U=W;
    }

    return TotalFare;
}
