#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR -1
#define INFINITY 65536

//���в���
Queue InitQueue(int MaxNum);
void EnQueue(Queue Q,ElementType X);
bool IsEmpty(Queue Q);
ElementType DeQueue(Queue Q);

//ͼ�Ĳ���
Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
Vertex CalEarliestTime(Graph G,WeightType Earliest[]);
WeightType CalLatestTime(Graph G,Vertex W,WeightType Latest[]);
void FindKeyActivities(Graph G,Vertex Start,WeightType Earliest[],WeightType Latest[]);
