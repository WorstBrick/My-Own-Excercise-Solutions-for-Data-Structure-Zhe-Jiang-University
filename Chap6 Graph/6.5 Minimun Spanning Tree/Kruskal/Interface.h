#include "Item.h"
#include <stdlib.h>

//最小堆的操作集
Heap InitHeap(int MaxNum);
bool IsFull(Heap H);
void UpFilt(Heap H,ElementType E);
bool Insert(Heap H,ElementType E);
bool IsEmpty(Heap H);
void DownFilt(Heap H,ElementType E);
ElementType Delete(Heap H);


//并查集的操作集
UFSet InitUFSet(int MaxNum);
Vertex Find(UFSet S,Vertex V);
bool UnionAndCheck(UFSet S,Vertex V,Vertex W);

//图的操作(图的基础操作就不写了,只有Kruskal)
void Kruskal(Graph G,Graph MST);
void InsertEdge(Graph,Edge);
