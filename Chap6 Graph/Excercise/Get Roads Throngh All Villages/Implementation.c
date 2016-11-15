#include "Interface.h"

Heap InitHeap(int MaxNum)
{
    Heap H=(Heap)malloc(sizeof(*H));
    H->MaxNum=MaxNum;
    H->CBT=(CBTree)malloc((MaxNum+1)*sizeof(HeapElement));
    H->CurrentIndex=0;

    return H;
}

void UpFilt(Heap H,HeapElement X)
{
    Position Child=H->CurrentIndex,Parent=Child/2;

    while (Parent>0 && H->CBT[Parent]->Cost > X->Cost)
    {
        H->CBT[Child]=H->CBT[Parent];
        Child=Parent;
        Parent=Child/2;
    }
    H->CBT[Child]=X;
}

void HeapInsert(Heap H,HeapElement X)
{
    (H->CurrentIndex)++;
    UpFilt(H,X);
}

bool IsEmpty(Heap H)
{
    return (H->CurrentIndex==0);
}

void DownFilt(Heap H,HeapElement X)
{
    Position Parent=1,Child=Parent*2;

    while (Child<=H->CurrentIndex)
    {
        if (H->CBT[Child]->Cost > H->CBT[Child+1]->Cost)
            Child++;
        if (H->CBT[Child]->Cost < X->Cost)
        {
            H->CBT[Parent]=H->CBT[Child];
            Parent=Child;
            Child=Parent*2;
        }
        else          //不要忘了这个跳出循环
            break;
    }
    H->CBT[Parent]=X;
}

HeapElement HeapDelete(Heap H)
{
    if (IsEmpty(H))
        return NULL;
    else
    {
        HeapElement E=(Edge)malloc(sizeof(*E));
        E->V1=H->CBT[1]->V1;
        E->V2=H->CBT[1]->V2;
        E->Cost=H->CBT[1]->Cost;
        HeapElement X=H->CBT[(H->CurrentIndex)--];
        DownFilt(H,X);

        return E;
    }
}

UFSet InitUFset(int MaxNum)
{
    UFSet S=(UFSet)malloc((MaxNum+1)*sizeof(SetElement));
    S[0]=MaxNum;
    SetElement X;
    MaxNum++;

    for (X=1;X<MaxNum;X++)
        S[X]=-1;

    return S;
}

SetElement Find(UFSet S,SetElement X)
{
    if (S[X]<0)
        return X;
    else
        return (S[X]=Find(S,S[X]));
}

bool UnionAndJudge(UFSet S,SetElement X,SetElement Y)
{
    SetElement rootX=Find(S,X),rootY=Find(S,Y);
    if (rootX==rootY)
        return false;
    if (S[rootX]<S[rootY])
    {
        S[rootX]+=S[rootY];
        S[rootY]=rootX;
    }
    else
    {
        S[rootY]+=S[rootX];
        S[rootX]=rootY;
    }
    return true;
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
        G->AllVer[W].Flag=true;
    }

    return G;
}

void InsertEdge(Graph G,Edge E)
{
    PtrToAdjNode NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->Cost=E->Cost;
    NewNode->V=E->V2;
    NewNode->Next=G->AllVer[E->V1].FirstEdge;
    G->AllVer[E->V1].FirstEdge=NewNode;

    NewNode=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->Cost=E->Cost;
    NewNode->V=E->V1;
    NewNode->Next=G->AllVer[E->V2].FirstEdge;
    G->AllVer[E->V2].FirstEdge=NewNode;
}

void BuildGraph(Graph G,int Ne)
{
    if ((G->Ne=Ne)!=0)
    {
        int i;
        Edge E=(Edge)malloc(sizeof(*E));
        for (i=0;i<Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Cost);
            (E->V1)--;
            (E->V2)--;
            InsertEdge(G,E);
        }
    }
}

WeightType Kruskal(Graph G)
{
    int cnt=0;
    WeightType ShortestLength=0;

    Heap H=InitHeap(G->Ne);
    AdjList T;
    Edge E;
    Vertex W;
    for (W=0;W<G->Nv;W++)
    {
        T=G->AllVer[W].FirstEdge;
        G->AllVer[W].Flag=false;
        while (T)
        {
            if (G->AllVer[T->V].Flag)
            {
                E=(Edge)malloc(sizeof(*E));
                E->V1=W+1;
                E->V2=T->V+1;
                E->Cost=T->Cost;
                HeapInsert(H,E);
                //G->AllVer[T->V].Flag=false;
            }
            T=T->Next;
        }
    }

    UFSet S=InitUFset(G->Nv);
    while (!IsEmpty(H))
    {
        E=HeapDelete(H);
        if (UnionAndJudge(S,E->V1,E->V2))
        {
            ShortestLength+=E->Cost;
            cnt++;
        }
    }

    if (cnt<G->Nv-1)
        return ERROR;
    else
        return ShortestLength;
}
