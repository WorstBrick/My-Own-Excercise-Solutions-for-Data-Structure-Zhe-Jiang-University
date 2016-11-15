#include "Graph.h"
#include <stdlib.h>
#include <stdbool.h>

//队列的操作集
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);


//图的操作集
MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph,Edge E);
MGraph BuildGraph(void);
bool IsEdge(MGraph Graph,Vertex V,Vertex W);
void DFS(MGraph G,Vertex S);
void BFS(MGraph G,Vertex S);
