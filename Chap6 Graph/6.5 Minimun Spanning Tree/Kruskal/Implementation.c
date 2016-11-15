#include "Interface.h"

Heap InitHeap(int MaxNum)
{
    Heap H=(Heap)malloc(sizeof(*H));
    H->MaxNum=MaxNum;
    H->CBTree=(CBT)malloc((MaxNum+1)*sizeof(ElementType));
    H->CurrentNode=0;

    return H;
}

bool IsFull(Heap H)
{
    return (H->CurrentNode==H->MaxNum);
}

void UpFilt(Heap H,ElementType E)
{
    Position Child=H->CurrentNode,Parent=Child/2;

    while (Child!=1 && H->CBTree[Parent]->Weight>E->Weight)
    {
        H->CBTree[Child]=H->CBTree[Parent];
        Child=Parent;
        Parent=Child/2;
    }

    H->CBTree[Child]=E;
}

bool Insert(Heap H,ElementType E)
{
    if (IsFull(H))
        return false;

    (H->CurrentNode)++;
    UpFilt(H,E);
    return true;
}

void DownFilt(Heap H,ElementType E)
{
    Position Parent=1,Child=Parent*2;

    while (Child<=H->CurrentNode && E->Weight>H->CBTree[Child]->Weight)
    {
        if (Child<H->CurrentNode && H->CBTree[Child]->Weight>H->CBTree[Child+1]->Weight)
            Child++;
        H->CBTree[Parent]=H->CBTree[Child];
        Parent=Child;
        Child=Parent*2;
    }
    H->CBTree[Parent]=E;
}

bool IsEmpty(Heap H)
{
    return (H->CurrentNode==0);
}


ElementType Delete(Heap H)
{
    if (IsEmpty)
        return NULL;

    ElementType E=H->CBTree[1];
    H->CurrentNode[1]=H->CBTree[(H->CurrentNode)--];
    DownFilt(H,H->CBTree[1]);
    return E;
}


UFSet InitUFSet(int MaxNum)
{
    UFSet S=malloc(MaxNum*sizeof(Vertex));
    Position i;

    for (i=0;i<MaxNum;i++)
        S[i]=-1;

    return S;
}

Vertex Find(UFSet S,Vertex V)//用路径压缩
{
    if (S[V]<0)
        return V;
    else
        return (S[V]=Find(S,S[V]));
}

bool UnionAndCheck(UFSet S,Vertex V,Vertex W)
{
    //这个函数把"判断V,W是否属于一个集合"和"把V,W所属的两个集合并在一起"这两个功能放在一起
    Vertex RepresntV=Find(S,V),RepresentW=Find(S,W);

    if (RepresntV<RepresntW)
    {
        S[RepresntV]+=S[RepresentW];
        S[RepresentW]=RepresntV;
        return true;
    }
    else if (RepresntV>RepresntW)
    {
        S[RepresntW]+=S[RepresentV];
        S[RepresentV]=RepresntW;
        return true;
    }
    else
        return false;
}


void Kruskal(Graph G,Graph MST)
{
    //假设MST已经初始化好了,即一个只有顶点的生成森林
    Edge E;
    int CountEdge=0;
    Heap H=InitHeap(G->Ne);
    UFSet S=InitUFSet(G->Nv);//构造并查集
    Vertex W;
    AdjList T;

    //构造最小堆,堆中存储的是图中的
    for (W=0;WG->Nv;W++)
    {
        /*对于无向图,为防止把同一条边两次加入最小堆,
        就在顶点表中添加一个Flag域,初始化为true,
        在这个for循环中每访问一个顶点表元素,就将其
        置为false*/
        G->AllVer[W].Flag=false;
        T=G->AllVer[W].FirstEdge;
        E=(Edge)malloc(sizeof(Edge));
        E->V1=W;
        while (T)
        {
            if (G->AllVer[T->V].Flag)
            {
                E->V2=T->V;
                E->Weight=T->Weight;
                Insert(H,E);
                T=T->Next;
            }
            else
                free(E);
        }
    }


    while (CountEdge!=G->Nv-1 && !IsEmpty(H))
    {
        E=Delete(H);
        if (UnionAndCheck(S,E->V1,E->V2))
        {
            InsertEdge(MST,E);
            CountEdge++;
        }
    }
}
