#include "Interface.h"

Queue InitQueue(int MaxNum)
{
    Queue Q=(Queue)malloc(sizeof(*Q));
    Q->MaxNum=MaxNum;
    Q->AllElement=(StorageSpace)malloc((MaxNum+1)*sizeof(ElementType));
    Q->Front=0;
    Q->Rear=1;

    return Q;
}

void EnQueue(Queue Q,ElementType X)
{
    Q->AllElement[Q->Rear]=X;
    Q->Rear=(Q->Rear+1)%(Q->MaxNum+1);
}

bool IsEmpty(Queue Q)
{
    return ((Q->Front+1)%(Q->MaxNum+1)==Q->Rear);
}

ElementType DeQueue(Queue Q)
{
    if (IsEmpty(Q))
        return ERROR;
    else
    {
        Q->Front=(Q->Front+1)%(Q->MaxNum+1);
        return Q->AllElement[Q->Front];
    }
}

Graph InitGraph(int Nv)
{
    Graph G=(Graph)malloc(sizeof(*G));
    G->Ne=0;
    G->Nv=Nv;
    G->AllVer=(VerList)malloc(Nv*sizeof(struct VNode));

    Vertex W;
    for (W=0;W<Nv;W++)
    {
        G->AllVer[W].FirstEdge=NULL;
        G->AllVer[W].InDegree1=0;
        G->AllVer[W].InDegree2=0;
    }

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->Time=E->Time;
    NewNode->V=E->V2;
    NewNode->Next=G->AllVer[E->V1].FirstEdge;
    G->AllVer[E->V1].FirstEdge=NewNode;
    (G->AllVer[E->V2].InDegree1)++;
    (G->AllVer[E->V2].InDegree2)++;
}

void BuildGraph(Graph G,int Ne)
{
    if ((G->Ne=Ne)!=0)
    {
        int i;
        Edge E=(Edge)malloc(sizeof(*E));
        for (i=0;i<Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Time);
            (E->V1)--;
            (E->V2)--;
            InsertEdge(G,E);
        }
    }
}

Vertex CalEarliestTime(Graph G,WeightType Earliest[])
{
    Queue Q=InitQueue(G->Nv);
    Vertex W;
    Vertex EndVer=0;
    AdjList T;
    int Cnt=0;
    for (W=0;W<G->Nv;W++)
    {
        Earliest[W]=0;
        if (G->AllVer[W].InDegree1==0)
            EnQueue(Q,W);
    }

    while (!IsEmpty(Q))
    {
        W=DeQueue(Q);
        Cnt++;
        T=G->AllVer[W].FirstEdge;
        while (T)
        {
            if (Earliest[W]+T->Time>Earliest[T->V])
                Earliest[T->V]=Earliest[W]+T->Time;
            if (Earliest[T->V]>Earliest[EndVer])
                EndVer=T->V;
            (G->AllVer[T->V].InDegree1)--;
            if (G->AllVer[T->V].InDegree1==0)
                EnQueue(Q,T->V);
            T=T->Next;
        }
    }

    if (Cnt==G->Nv)
        return EndVer;
    else
        return ERROR;
}

WeightType CalLatestTime(Graph G,Vertex W,WeightType Latest[])//Latest数组中的"终点"初始化为
{                                                             //Earliest数组中对应的值,其他的
                                                            //非"终点"顶点则初始化为INFINITY
    WeightType TmpTime;//TmpTime在这个过程中暂存顶点W所有邻接点的LatestTime再减掉
                        //W与与该邻接点的距离
    AdjList T=G->AllVer[W].FirstEdge;
    while (T)//若W是"终点"顶点,则其无出边,所以T直接等于NULL,跳出循环
    {
        TmpTime=CalLatestTime(G,T->V,Latest)-T->Time;
        if (TmpTime<Latest[W])
            Latest[W]=TmpTime;
        T=T->Next;
    }

    return Latest[W];
}

void FindKeyActivities(Graph G,Vertex Start,WeightType Earliest[],WeightType Latest[])
{
    AdjList T;
    Queue Q=InitQueue(G->Nv);
    EnQueue(Q,Start);

    while (!IsEmpty(Q))
    {
        Start=DeQueue(Q);
        T=G->AllVer[Start].FirstEdge;
        while (T)
        {
            if (Latest[T->V]-Earliest[Start]-T->Time==0)
            {
                printf("%d->%d\n",Start+1,T->V+1);
                EnQueue(Q,T->V);
            }
            T=T->Next;
        }
    }
}
