#include "Interface.h"

Heap InitHeap(int MaxNum)
{
    Heap H=(Heap)malloc(sizeof(*H));
    H->MaxNum=MaxNum;
    H->CurrentNode=0;
    H->CBTree=(CBT)malloc((MaxNum+1)*sizeof(ElementType));//����CBT��ʾ,���±�Ϊ1��ʼ

    return H;
}


bool IsFull(Heap H)
{
    return (H->CurrentNode==H->MaxNum);
}


void UpFilt(Heap H,ElementType X,PtrToDNode dist)//ͨ�ð������
{
    Position Child=dist[X].Index,Parent=Child/2;//�Ӷ���X�ڶ��е��±꿪ʼ

    while (Parent>=1 && dist[H->CBTree[Parent]].ShortestLength>dist[X].ShortestLength)
    {
        H->CBTree[Child]=H->CBTree[Parent];
        dist[H->CBTree[Child]].Index=Child;//dist[H->CBTree[Parent]].Index;
        Child=Parent;
        Parent=Child/2;
    }
    H->CBTree[Child]=X;
    dist[X].Index=Child;
}

bool HeapInsert(Heap H,ElementType X,PtrToDNode dist)
{
    if (IsFull(H))
        return false;
    else
    {
        (H->CurrentNode)++;
        dist[X].Index=H->CurrentNode;//��¼����X��������к�,���ڶ��е��±�
        UpFilt(H,X,dist);
        return true;
    }
}

bool IsEmpty(Heap H)
{
    return (H->CurrentNode==0);
}

static Position MinOne(Heap H,Position Parent,PtrToDNode dist)
{
    Position Child=2*Parent;
    if (Child<H->CurrentNode && dist[H->CBTree[Child]].ShortestLength>dist[H->CBTree[Child+1]].ShortestLength)
        Child++;
    return Child;
}

void DownFilt(Heap H,ElementType X,PtrToDNode dist)
{
    Position Parent=1,Child=MinOne(H,Parent,dist);

    while(Child<=H->CurrentNode && dist[H->CBTree[Child]].ShortestLength<dist[X].ShortestLength)
    {
        H->CBTree[Parent]=H->CBTree[Child];
        dist[H->CBTree[Parent]].Index=Parent;
        Parent=Child;
        Child=MinOne(H,Parent,dist);
    }
    H->CBTree[Parent]=X;
    dist[X].Index=Parent;
}

Vertex HeapDelete(Heap H,int boundary,Result Output,int Index,PtrToDNode dist)
{
    if (IsEmpty(H))
        return false;
    else
    {
        Vertex V=H->CBTree[1];//ÿ�ζ���ɾ�����еĸ��ڵ�(��Ϊ����С)
        if (V<boundary)//boundary���������ַ��ӽڵ������վ�ڵ�Ľ���.����0~(Nhv-1)Ϊ����,Nhv+Ngv-1Ϊ��վ"�ƻ���"
        {              //����boundary��ΪG->Nhv
            if (dist[V].ShortestLength<Output[Index].ShortestLength)
                Output[Index].ShortestLength=dist[V].ShortestLength;
            Output[Index].AverageLength+=(double)dist[V].ShortestLength;
        }
        ElementType X=H->CBTree[(H->CurrentNode)--];
        DownFilt(H,X,dist);
        return V;
    }
}

Graph InitGraph(int Nhv,int Ngv)//�Է��ӵ������ͼ���վ"�ƻ���"��������Ϊ����
{
    Graph G=(Graph)malloc(sizeof(*G));
    G->Nhv=Nhv;
    G->Ngv=Ngv;
    G->Ne=0;
    G->AllVer=(VerList)malloc((Nhv+Ngv)*sizeof(struct VNode));

    int i;
    Nhv+=Ngv;
    for (i=0;i<Nhv;i++)
        G->AllVer[i].FirstEdge=NULL;

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->Length=E[2];
    NewNode->V=E[1];
    NewNode->Next=G->AllVer[E[0]].FirstEdge;
    G->AllVer[E[0]].FirstEdge=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->Length=E[2];
    NewNode->V=E[0];
    NewNode->Next=G->AllVer[E[1]].FirstEdge;
    G->AllVer[E[1]].FirstEdge=NewNode;
}

void BuildGraph(Graph G,int Ne)
{
    if ((G->Ne=Ne)!=0)
    {
        Edge E=(Edge)malloc(3*sizeof(int));
        int i,j,tmp;

        for (i=0;i<Ne;i++)
        {
            for (j=0;j<3;j++)
            {
                if (scanf("%d",&tmp)==0)
                {
                    getchar();
                    scanf("%d",&tmp);
                    E[j]=tmp+G->Nhv;
                }
                else
                    E[j]=tmp;

            }
            E[0]--;
            E[1]--;
            InsertEdge(G,E);
        }
    }
}

void DijkstraModified(Graph G,Vertex S,Result Output,int Index)//�Ը��㷨���и��Ӷȷ���
{
    int Nv=G->Nhv+G->Ngv;
    Heap H=InitHeap(Nv);
    PtrToDNode dist=(PtrToDNode)malloc(Nv*sizeof(struct DNode));
    Vertex W;

    for (W=0;W<Nv;W++)//�������������ڳ�ʼ����forѭ��,���Ӷ�ΪO(Nv)
        dist[W].ShortestLength=INFINITY;
    dist[S].ShortestLength=0;
    AdjList T=G->AllVer[S].FirstEdge;
    while (T)
    {
        dist[T->V].ShortestLength=T->Length;
        T=T->Next;
    }
    for (W=0;W<Nv;W++)
        HeapInsert(H,W,dist);

    while (!IsEmpty(H))//�������ѭ��,���Ӷ�ΪO(Nv*log(Nv)+E),����EΪ�ܱ���
    {
        W=HeapDelete(H,G->Nhv,Output,Index,dist);
        T=G->AllVer[W].FirstEdge;
        while (T)
        {
            if (T->Length+dist[W].ShortestLength<dist[T->V].ShortestLength)
            {
                dist[T->V].ShortestLength=T->Length+dist[W].ShortestLength;
                UpFilt(H,T->V,dist);
            }
            T=T->Next;
        }
    }
    Output[Index].AverageLength/=G->Nhv;
}

bool Solution(Result Output,int Distance,int GasNum)
{
    int MinDistance=0,GasStation,i;
    double MinAverage=INFINITY;

    for (i=0;i<GasNum;i++)
    {
        if (Output[i].ShortestLength<=Distance)
        {
            if (Output[i].ShortestLength>MinDistance)
            {
                GasStation=i;
                MinAverage=Output[i].AverageLength;
                MinDistance=Output[i].ShortestLength;
            }
            else if (Output[i].ShortestLength==MinDistance && Output[i].AverageLength<MinAverage)
            {
                GasStation=i;
                MinAverage=Output[i].AverageLength;
            }
        }
    }

    if (MinDistance==0)
        return true;
    else
    {
        double ShortestLength=(double)Output[GasStation].ShortestLength;
        printf("G%d\n",GasStation+1);
        printf("%.1f %.1f",ShortestLength,Output[GasStation].AverageLength);
        return false;
    }
}
