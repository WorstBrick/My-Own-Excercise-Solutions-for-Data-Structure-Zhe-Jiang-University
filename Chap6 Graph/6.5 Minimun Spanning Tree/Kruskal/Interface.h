#include "Item.h"
#include <stdlib.h>

//��С�ѵĲ�����
Heap InitHeap(int MaxNum);
bool IsFull(Heap H);
void UpFilt(Heap H,ElementType E);
bool Insert(Heap H,ElementType E);
bool IsEmpty(Heap H);
void DownFilt(Heap H,ElementType E);
ElementType Delete(Heap H);


//���鼯�Ĳ�����
UFSet InitUFSet(int MaxNum);
Vertex Find(UFSet S,Vertex V);
bool UnionAndCheck(UFSet S,Vertex V,Vertex W);

//ͼ�Ĳ���(ͼ�Ļ��������Ͳ�д��,ֻ��Kruskal)
void Kruskal(Graph G,Graph MST);
void InsertEdge(Graph,Edge);
