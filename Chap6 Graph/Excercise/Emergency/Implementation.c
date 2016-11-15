#include "Interface.h"

Graph InitGraph(int Nv)
{
    Graph G=(Graph)malloc(sizeof(*G));
    G->Ne=0;
    G->Nv=Nv;
    G->AllVer=(VerList)malloc(Nv*sizeof(struct VNode));

    DataType MensNumber;
    Vertex V;

    for (V=0;V<Nv;V++)
    {
        scanf("%d",&MensNumber);
        G->AllVer[V].FirstEdge=NULL;
        G->AllVer[V].MensNumber=MensNumber;
    }

    return G;
}


void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->Length=E->Length;
    NewNode->V=E->V2;
    NewNode->Next=G->AllVer[E->V1].FirstEdge;
    G->AllVer[E->V1].FirstEdge=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->Length=E->Length;
    NewNode->V=E->V1;
    NewNode->Next=G->AllVer[E->V2].FirstEdge;
    G->AllVer[E->V2].FirstEdge=NewNode;
}


void BuildGraph(Graph G,int Ne)
{
    if ((G->Ne=Ne)!=0)
    {
        Edge E=(Edge)malloc(sizeof(*E));
        int i;

        for (i=0;i<Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Length);
            InsertEdge(G,E);
        }
    }
}


Vertex FindMinDist(Graph G,WeightType * dist,bool collected[])
{
    Vertex W,MinVer;
    WeightType MinLength=INFINITY;

    for (W=0;W<G->Nv;W++)
    {
        if (collected[W] && dist[W]<MinLength)
        {
            MinLength=dist[W];
            MinVer=W;
        }
    }

    if (MinLength==INFINITY)
        return ERROR;
    else
        return MinVer;
}


//作为参数的两个数组已经分配好空间了,但初始化还是在本函数内进行
void DijkstraModified(Graph G,Vertex S,int CountRoad[],int RescueMen[])
{
    WeightType * dist=(WeightType *)malloc((G->Nv)*sizeof(WeightType));
    bool * collected=(bool *)malloc((G->Nv)*sizeof(bool));
    Vertex W;
    AdjList T;

    for (W=0;W<G->Nv;W++)
    {
        collected[W]=true;
        dist[W]=INFINITY;
        CountRoad[W]=0;
        RescueMen[W]=G->AllVer[S].MensNumber;
        //RescueMen[W]=G->AllVer[W].MensNumber;
    }

    T=G->AllVer[S].FirstEdge;
    while (T)
    {
        dist[T->V]=T->Length;
        RescueMen[T->V]+=G->AllVer[T->V].MensNumber;
        T=T->Next;
    }
    dist[S]=0;
    //RescueMen[S]=G->AllVer[S].MensNumber;
    CountRoad[S]=1;

    while (1)
    {
        W=FindMinDist(G,dist,collected);
        if (W==ERROR)
            break;
        collected[W]=false;
        T=G->AllVer[W].FirstEdge;
        while (T)
        {
            if (dist[W]+T->Length<dist[T->V])
            {
                dist[T->V]=dist[W]+T->Length;
                CountRoad[T->V]=CountRoad[W];
                RescueMen[T->V]=RescueMen[W]+G->AllVer[T->V].MensNumber;
            }
            else if (dist[W]+T->Length==dist[T->V])
            {
                CountRoad[T->V]+=CountRoad[W];
                if (RescueMen[W]+G->AllVer[T->V].MensNumber>RescueMen[T->V])
                    RescueMen[T->V]=RescueMen[W]+G->AllVer[T->V].MensNumber;
            }
            T=T->Next;
        }
    }
}
