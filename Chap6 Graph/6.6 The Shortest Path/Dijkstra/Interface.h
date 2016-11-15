#include "MGraph.h"
#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 1000
#define ERROR -1

//����Ȩͼ�����·����Ҫ�õ�����
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

//����Ȩͼ�����·��,��������dist��path����ʼ����
void UnWeighted(Graph G,int dist[],int path[],Vertex S);
