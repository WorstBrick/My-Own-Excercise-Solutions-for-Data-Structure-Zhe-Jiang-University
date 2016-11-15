#include "Interface.h"
#define ERROR -1
bool * Visited;

Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof *Q);
    Q->Data=(ElementType *)malloc(MaxSize);
    Q->Front=0;
    Q->Rear=0;
    Q->MaxSize=MaxSize;

    return Q;
}

bool IsFull(Queue Q)
{
    //return (Q->Front-(Q->Rear%Q->Maxsize)==1);
    return ((Q->Rear+1)%Q->MaxSize==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
    if (IsFull(Q))
    {
        printf("The Queue is fully.\n");
        return false;
    }
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
    {
        printf("The queue is empty.\n");
        return ERROR;
    }
    Q->Front=(Q->Front+1)%(Q->MaxSize);
    ElementType X=Q->Data[Q->Front];

    return X;
}

Graph InitGraph(int N)
{
    int i;
    Graph G=(Graph)malloc(sizeof(*G));
    G->Nv=N;
    G->PresentV=1;
    G->AllVer=(VerList)malloc(N*sizeof(struct VNode));
    G->AllVer[0].Flag=END;
    G->AllVer[N-1].Flag=END;

    for (i=0;i<N;i++)
    {
        if (i && i!=N-1)
            G->AllVer[i].P=(Coordinate)malloc(sizeof(struct CoorNode));
        G->AllVer[i].FirstEdge=(AdjList)malloc(sizeof(struct AdjNode));
        G->AllVer[i].FirstEdge->Next=NULL;
    }
    return G;
}

static double Min(Coordinate P)
{
    double num1,num2;
    if (P->X>0)
        num1=50-P->X;
    else
        num1=P->X+50;
    if (P->Y>0)
        num2=50-P->Y;
    else
        num2=P->Y+50;

    return (num1<num2?num1:num2);
}
static bool CalDistance(Graph G,Vertex V,Coordinate P,double D)
{
    double distance;
    if (!V)
        distance=sqrt(pow(P->X,2)+pow(P->Y,2))-7.5;
    else if (V==G->Nv-1)
        distance=Min(P);
    else
        distance=sqrt(pow(G->AllVer[V].P->X-P->X,2)+pow(G->AllVer[V].P->Y-P->Y,2));

    return (distance<=D);
}

void InsertVer(Graph G,Vertex V1,Vertex V2)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=V2;
    NewNode->Next=G->AllVer[V1].FirstEdge->Next;
    G->AllVer[V1].FirstEdge->Next=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=V1;
    NewNode->Next=G->AllVer[V2].FirstEdge->Next;
    G->AllVer[V2].FirstEdge->Next=NewNode;
}

static void InsertEnd(Graph G,Vertex V)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=G->Nv-1;
    NewNode->Next=G->AllVer[V].FirstEdge->Next;
    G->AllVer[V].FirstEdge->Next=NewNode;
}
void BuildGraph(Graph G,double D)
{
    int N=G->Nv;
    N--;
    Coordinate P=(Coordinate)malloc(sizeof(*P));
    Vertex V,W;

    for (V=1;V<N;V++)
    {
        scanf("%lf %lf",&P->X,&P->Y);
        G->AllVer[V].P->X=P->X;
        G->AllVer[V].P->Y=P->Y;
        for (W=0;W<G->PresentV;W++)
            if (CalDistance(G,W,P,D))
                InsertVer(G,W,V);
        (G->PresentV)++;
    }
    for (W=1;W<N;W++)
        if (CalDistance(G,N,G->AllVer[W].P,D))
            InsertEnd(G,W);
}


bool BFS(Graph G)
{
    Vertex Bank=G->Nv-1;
    Queue Q=CreateQueue(G->Nv);
    Vertex V;
    PtrToAdjNode T;
    AddQ(Q,0);

    while (!IsEmpty(Q))
    {
        V=DeleteQ(Q);
        if (Visited[V])
            continue;
        Visited[V]=true;
        T=G->AllVer[V].FirstEdge->Next;
        while (T)
        {
            if (T->V==Bank)
                return true;
            if (!Visited[T->V])
                AddQ(Q,T->V);
            T=T->Next;
        }
    }
    return false;
}
