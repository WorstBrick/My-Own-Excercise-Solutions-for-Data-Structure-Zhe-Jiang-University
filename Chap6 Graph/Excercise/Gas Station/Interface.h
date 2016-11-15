#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 65536

//堆的操作
Heap InitHeap(int MaxNum);
void UpFilt(Heap H,ElementType X,PtrToDNode dist);
bool IsFull(Heap H);
bool HeapInsert(Heap H,ElementType X,PtrToDNode dist);
bool IsEmpty(Heap H);
void DownFilt(Heap H,ElementType X,PtrToDNode dist);
Vertex HeapDelete(Heap H,int boundary,Result Output,int Index,PtrToDNode dist);


//图的操作
Graph InitGraph(int Nhv,int Nge);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
void DijkstraModified(Graph G,Vertex S,Result Output,int Index);

//对存储最终结果的结构进行的操作
bool Solution(Result Output,int Distance,int GasNum);
