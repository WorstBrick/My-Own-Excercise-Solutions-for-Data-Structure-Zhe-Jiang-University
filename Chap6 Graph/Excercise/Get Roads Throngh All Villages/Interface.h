#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#define ERROR -1

//�ѵĲ���
Heap InitHeap(int MaxNum);
void UpFilt(Heap H,HeapElement X);
void HeapInsert(Heap H,HeapElement X);
bool IsEmpty(Heap H);
void DownFilt(Heap H,HeapElement X);
HeapElement HeapDelete(Heap H);

//���鼯
UFSet InitUFset(int MaxNum);
SetElement Find(UFSet S,SetElement X);
bool UnionAndJudge(UFSet S,SetElement X,SetElement Y);

//ͼ�Ĳ���
Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
WeightType Kruskal(Graph G);
