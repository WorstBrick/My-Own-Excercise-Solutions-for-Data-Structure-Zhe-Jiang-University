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
    int i;

    Graph G=(Graph)malloc(sizeof(*G));
    G->Ne=0;
    G->Nv=Nv;
    G->AllVer=(VerList)malloc((Nv+1)*sizeof(struct VNode));

    for (i=0;i<Nv+1;i++)
        G->AllVer[i].FirstEdge=NULL;
    return G;
}

void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->V=E->V2;
    NewNode->Next=G->AllVer[E->V1].FirstEdge;
    G->AllVer[E->V1].FirstEdge=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->V=E->V1;
    NewNode->Next=G->AllVer[E->V2].FirstEdge;
    G->AllVer[E->V2].FirstEdge=NewNode;
}

void BuildGraph(Graph G,int Ne)
{
    if (Ne!=0)
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


int InZoneVer(Graph G,Vertex V,Queue Q)
{
    int Layer=0;//Layer��ʾ��ǰ�Ĳ���
    Vertex Last=V;//Last�ǵ�ǰ������һ������
    Vertex W,Tail;//Tail����һ������һ������
    int cnt=1;
    PtrToAdjNode T;

    Visited[V]=true;
    AddQ(Q,V);

    while (!IsEmpty(Q))
    {
        V=DeleteQ(Q);
        T=G->AllVer[V].FirstEdge;
        while (T)//��ѭ����������V�������ڽӵ�,��W��ʾ
        {
            W=T->V;
            if (!Visited[W])
            {
                cnt++;
                Visited[W]=true;
                Tail=W;//��Ϊ��ǰ���ʵ��Ƕ���V���ڵĲ�,��ôV���ڽӵ���Ȼ��������һ��,��Tail��ʱ����"��һ������һ������"
                AddQ(Q,W);
            }
            T=T->Next;
        }
        if (V==Last)//��V���ڵ�ǰ������һ������Lastʱ,��Ȼ�ض�ĳһ��ı����ͽ�����,����Layer++
        {
            Layer++;
            Last=Tail;//ͬʱLast(����ǰ������һ������)����Ϊ��һ������һ������Tail
        }
        if (Layer==6)//������Ϊ6ʱ,��������
            break;
    }

    return cnt;
}
