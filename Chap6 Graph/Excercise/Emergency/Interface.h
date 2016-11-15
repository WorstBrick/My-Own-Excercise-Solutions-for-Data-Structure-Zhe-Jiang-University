#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define INFINITY 65536
#define ERROR -1

Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
void DijkstraModified(Graph G,Vertex S,int CountRoad[],int RescueMen[]);
Vertex FindMinDist(Graph G,WeightType * dist,bool collected[]);
