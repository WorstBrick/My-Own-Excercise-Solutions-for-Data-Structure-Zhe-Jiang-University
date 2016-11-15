#include "Interface.h"

Queue InitQueue(int MaxNum)
{
    Queue Q=(Queue)malloc(sizeof(*Q));
    Q->MaxNum=MaxNum;
    Q->Front=0;
    Q->Rear=1;
    Q->StorageSpace=(StorageForm)malloc((MaxNum+1)*sizeof(ElementType));

    return Q;
}

bool IsFull(Queue Q)
{
    return (Q->Front==Q->Rear);
}

void EnQueue(Queue Q,ElementType X)
{
    if (IsFull(Q))
        return;
    Q->StorageSpace[Q->Rear]=X;
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
    Q->Front=(Q->Front+1)%(Q->MaxNum+1);
    ElementType X=Q->StorageSpace[Q->Front];
    return X;
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
        G->AllVer[W].InDegree=0;
    }

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=E->V2;
    NewNode->Next=G->AllVer[E->V1].FirstEdge;
    G->AllVer[E->V1].FirstEdge=NewNode;
    (G->AllVer[E->V2].InDegree)++;
}

void BuildGraph(Graph G,int Ne)
{
    if ((G->Ne=Ne)!=0)
    {
        int i;
        Edge E=(Edge)malloc(sizeof(*E));

        for (i=0;i<Ne;i++)
        {
            scanf("%d %d",&E->V1,&E->V2);
            InsertEdge(G,E);
        }
    }
}

bool TopoSort(Graph G,Vertex SortedVer[])
{
    Queue Q=InitQueue(G->Nv);
    Vertex W;
    AdjList T;
    int Cnt=0;
    for (W=0;W<G->Nv;W++)
    {
        if (G->AllVer[W].InDegree==0)
            EnQueue(Q,W);
    }

    while (!IsEmpty(Q))
    {
        W=DeQueue(Q);
        SortedVer[Cnt++]=W;
        T=G->AllVer[W].FirstEdge;
        while (T)
        {
            (G->AllVer[T->V].InDegree)--;
            if (G->AllVer[T->V].InDegree==0)
                EnQueue(Q,T->V);
            T=T->Next;
        }
    }

    if (Cnt==G->Nv)
        return true;
    else
        return false;

}
