#include "LGraph.h"
#include <stdbool.h>

//仅仅写出用邻接表实现的Dijkstra算法
Vertex FindMin(Graph G,int dist[],bool collected[]);
bool Dijkstra(Graph G,Vertex S,int dist[],Vertex path[],bool collected[]);
