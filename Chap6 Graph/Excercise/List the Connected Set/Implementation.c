#include "Interface.h"
bool * VisitedDFS;
bool * VisitedBFS;

//队列的操作集的具体实现
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof *Q);
    Q->Data=(StorageWay)malloc((MaxSize+1)*sizeof(ElementType));
    Q->Front=0;
    Q->Rear=0;
    Q->MaxSize=MaxSize;

    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%(Q->MaxSize+1)==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
    if (IsFull(Q))
        return false;
    else
    {
        Q->Rear=(Q->Rear+1)%(Q->MaxSize+1);
        Q->Data[Q->Rear]=X;
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
        return ERROR;
    else
    {
        Q->Front=(Q->Front+1)%(Q->MaxSize+1);
        ElementType X=Q->Data[Q->Front];
        return X;
    }
}


Graph InitGraph(int N)
{
    Graph G=(Graph)malloc(sizeof(*G));
    int i;
    G->Ne=0;
    G->Nv=N;
    G->AllVers=(VerList)malloc(N*sizeof(struct VNode));
    for (i=0;i<N;i++)
    {
        G->AllVers[i].FirstEdge=NULL;
        VisitedBFS[i]=true;
        VisitedDFS[i]=true;
    }

    return G;
}

void InsertEdge(Graph G,Edge tmp)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=tmp->V2;
    NewNode->Next=G->AllVers[tmp->V1].FirstEdge;
    G->AllVers[tmp->V1].FirstEdge=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->V=tmp->V1;
    NewNode->Next=G->AllVers[tmp->V2].FirstEdge;
    G->AllVers[tmp->V2].FirstEdge=NewNode;
}

void BuildGraph(Graph G,int E)
{
    if ((G->Ne=E)!=0)
    {
        Edge tmp=(Edge)malloc(sizeof(*tmp));
        int i;

        for (i=0;i<E;i++)
        {
            scanf("%d %d",&tmp->V1,&tmp->V2);
            InsertEdge(G,tmp);
        }
    }

}

void Visit(Vertex V)
{
    printf(" %d",V);
}

void DFS(Graph G,Vertex V)
{
    if (VisitedDFS[V])
    {
        Visit(V);
        VisitedDFS[V]=false;
        AdjList T=G->AllVers[V].FirstEdge;
        while (T)
        {
            DFS(G,T->V);
            T=T->Next;
        }
    }
}


void BFS(Graph G,Vertex V)
{
    Queue Q=CreateQueue(G->Nv);
    PtrToAdjNode T;
    AddQ(Q,V);

    while (!IsEmpty(Q))
    {
        V=DeleteQ(Q);
        if (!VisitedBFS[V])
            continue;
        Visit(V);
        VisitedBFS[V]=false;
        T=G->AllVers[V].FirstEdge;
        while (T)
        {
            if (VisitedBFS[T->V])
                AddQ(Q,T->V);
            T=T->Next;
        }
    }
}

static Vertex FindStartPoint(bool * Visited,int N)
{
    Vertex V;
    bool Flag=false;

    for (V=0;V<N;V++)
    {
        if (Visited[V])
        {
            Flag=true;
            break;
        }
    }
    if (Flag)
        return V;
    else
        return ERROR;
}

void TravelAll_DFS(Graph G)
{
    Vertex W;

    while (true)
    {
        W=FindStartPoint(VisitedDFS,G->Nv);
        if (W==ERROR)
            break;
        else
        {
            printf("{");
            DFS(G,W);
            printf(" }\n");
        }
    }
}

void TravelAll_BFS(Graph G)
{
    Vertex W;

    while (true)
    {
        W=FindStartPoint(VisitedBFS,G->Nv);
        if (W==ERROR)
            break;
        else
        {
            printf("{");
            BFS(G,W);
            printf(" }\n");
        }
    }
}
