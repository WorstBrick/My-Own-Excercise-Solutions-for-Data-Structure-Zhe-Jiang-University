#include "LGraph.h"
#include <stdbool.h>

//����д�����ڽӱ�ʵ�ֵ�Dijkstra�㷨
Vertex FindMin(Graph G,int dist[],bool collected[]);
bool Dijkstra(Graph G,Vertex S,int dist[],Vertex path[],bool collected[]);
