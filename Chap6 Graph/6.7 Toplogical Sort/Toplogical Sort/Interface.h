#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ERROR -1

//队列的操作
Queue InitQueue(int MaxNum);
bool IsFull(Queue Q);
void EnQueue(Queue Q,ElementType X);
bool IsEmpty(Queue Q);
ElementType DeQueue(Queue Q);

//图的操作
Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
bool TopoSort(Graph G,Vertex SortedVer[]);
