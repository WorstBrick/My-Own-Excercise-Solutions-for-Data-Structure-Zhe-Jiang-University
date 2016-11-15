#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define INFINITY 65536
#define ERROR -1

Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
Vertex FindBestVer(Graph G,WeightType dist[],bool collected[]);
WeightType * Dijkstra(Graph G,Vertex S,Vertex * path);
WeightType FindTotalFare(Graph G,Vertex D,Vertex * path);
