#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 65536

//�ѵĲ���
Heap InitHeap(int MaxNum);
void UpFilt(Heap H,ElementType X,PtrToDNode dist);
bool IsFull(Heap H);
bool HeapInsert(Heap H,ElementType X,PtrToDNode dist);
bool IsEmpty(Heap H);
void DownFilt(Heap H,ElementType X,PtrToDNode dist);
Vertex HeapDelete(Heap H,int boundary,Result Output,int Index,PtrToDNode dist);


//ͼ�Ĳ���
Graph InitGraph(int Nhv,int Nge);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
void DijkstraModified(Graph G,Vertex S,Result Output,int Index);

//�Դ洢���ս���Ľṹ���еĲ���
bool Solution(Result Output,int Distance,int GasNum);
