#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ERROR -1

Graph InitGraph(int Nv);
void InsertEdge(Graph G,Vertex V1,Vertex V2);
void BuildGraph(Graph G);
int BFS(Graph G,Vertex V,Queue Q,int Layer);

Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);
void CleanQueue(Queue Q);
