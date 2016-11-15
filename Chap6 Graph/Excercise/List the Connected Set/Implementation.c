#include "Interface.h"
bool * Visited;

//队列的操作集的具体实现
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
    Graph G=(Graph)malloc(sizeof(*G));
    int i;
    G->Ne=0;
    G->Nv=N;
    G->AllNodes=(Node)malloc(N*sizeof(PtrToAdjNode));
    for (i=0;i<N;i++)
    {
        G->AllNodes[i]=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
        G->AllNodes[i]->Next=NULL;
    }

    return G;
}

void InsertEdge(Graph G,Edge tmp)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=tmp->V2;
    PtrToAdjNode T=G->AllNodes[tmp->V1];
    while (T->Next && tmp->V2>T->Next->V)
        T=T->Next;
    NewNode->Next=T->Next;
    T->Next=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(*NewNode));
    NewNode->V=tmp->V1;
    T=G->AllNodes[tmp->V2];
    while (T->Next && tmp->V1>T->Next->V)
        T=T->Next;
    NewNode->Next=T->Next;
    T->Next=NewNode;
}

bool BuildGraph(Graph G,int E)
{
    if (!E)
        return false;

    G->Ne=E;
    Edge tmp=(Edge)malloc(sizeof(*tmp));
    int i;

    for (i=0;i<E;i++)
    {
        scanf("%d %d",&tmp->V1,&tmp->V2);
        InsertEdge(G,tmp);
    }
    return true;
}

void Visit(Vertex V)
{
    printf(" %d",V);
}

void DFS(Graph G,Vertex V)
{
    PtrToAdjNode W=(G->AllNodes)[V]->Next;
    //if (!Visited[V])
    /*{*/
        Visit(V);
        Visited[V]=true;
    //}
    while (W)
    {
        if (!Visited[W->V])
            DFS(G,W->V);
        W=W->Next;
    }
}


void BFS(Graph G,Vertex V)
{
    Queue Q=CreateQueue(G->Nv);
    PtrToAdjNode tmp;
    AddQ(Q,V);

    while (!IsEmpty(Q))
    {
        V=DeleteQ(Q);
        if (Visited[V])
            continue;
        Visit(V);
        Visited[V]=true;
        tmp=G->AllNodes[V]->Next;
        while (tmp)
        {
            if (!Visited[tmp->V])
                AddQ(Q,tmp->V);
            tmp=tmp->Next;
        }
    }
    free(Q);
}

void TravelAll_DFS(Graph G)
{
    Vertex V;
    int N=G->Nv;

    for (V=0;V<N;V++)
    {
        if (!Visited[V])
        {
            printf("{");
            DFS(G,V);
            printf(" }\n");
        }
    }
}

void TravelAll_BFS(Graph G)
{
    Vertex V;
    int N=G->Nv;

    for (V=0;V<N;V++)
    {
        if (!Visited[V])
        {
            printf("{");
            BFS(G,V);
            printf(" }\n");
        }
    }
}
