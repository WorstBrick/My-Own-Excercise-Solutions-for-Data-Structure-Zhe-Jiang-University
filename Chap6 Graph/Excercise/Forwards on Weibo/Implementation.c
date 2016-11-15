#include "Interface.h"

bool * Visited;
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof *Q);
    Q->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    Q->Front=0;
    Q->Rear=0;
    Q->MaxSize=MaxSize;

    return Q;
}

void CleanQueue(Queue Q)
{
    Q->Front=0;
    Q->Rear=0;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%Q->MaxSize==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
    if (IsFull(Q))
        return false;

    Q->Rear=(Q->Rear+1)%Q->MaxSize;
    Q->Data[Q->Rear]=X;
    return true;
}

bool IsEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
        return ERROR;

    Q->Front=(Q->Front+1)%(Q->MaxSize);
    ElementType X=Q->Data[Q->Front];

    return X;
}

Graph InitGraph(int Nv)
{
    Graph G=(Graph)malloc(sizeof(*G));
    int i;
    G->Nv=Nv;
    G->Ne=0;

    G->AllNode=(NodeList)malloc((Nv+1)*sizeof(struct VNode));
    for (i=0;i<Nv+1;i++)
        G->AllNode[i].FirstEdge=NULL;

    return G;
}

void InsertEdge(Graph G,Vertex V1,Vertex V2)//°ÑV2²åµ½V1ÉÏ
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->V=V2;
    NewNode->Next=G->AllNode[V1].FirstEdge;
    G->AllNode[V1].FirstEdge=NewNode;
}


void BuildGraph(Graph G)
{
    int Nv=G->Nv;
    int num,i;
    Vertex V1,V2;

    for (V2=1;V2<Nv+1;V2++)
    {
        scanf("%d",&num);
        for (i=0;i<num;i++)
        {
            scanf("%d",&V1);
            InsertEdge(G,V1,V2);
        }
    }
}

int BFS(Graph G,Vertex V,Queue Q,int Layer)
{
    int Level=0,cnt=0;
    PtrToAdjNode T;
    Vertex W,Tail=V,Last=V;

    AddQ(Q,V);
    Visited[V]=true;

    while(!IsEmpty(Q))
    {
        V=DeleteQ(Q);
        T=G->AllNode[V].FirstEdge;
        while (T)
        {
            W=T->V;
            if (!Visited[W])
            {
                cnt++;
                AddQ(Q,W);
                Visited[W]=true;
                Tail=W;
            }
            T=T->Next;
        }
        if (Last==V)
        {
            Level++;
            Last=Tail;
        }
        if (Level==Layer)
            break;
    }

    return cnt;
}
