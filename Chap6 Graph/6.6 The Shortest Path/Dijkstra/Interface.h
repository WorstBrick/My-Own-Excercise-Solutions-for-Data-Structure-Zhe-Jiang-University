#include "MGraph.h"
#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 1000
#define ERROR -1

//求无权图的最短路径中要用到队列
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);


Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
void FindMinDist(Graph G,int dist[],bool collected[]);
bool Dijkstra(Graph G,int dist[],int path[],Vertex S);

//求无权图的最短路径,假设数组dist和path都初始化了
void UnWeighted(Graph G,int dist[],int path[],Vertex S);
