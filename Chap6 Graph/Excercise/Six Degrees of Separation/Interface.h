#include "Item.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

//队列操作
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);
void CleanQueue(Queue Q);

//图的操作接口
Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
int InZoneVer(Graph G,Vertex V,Queue Q);
