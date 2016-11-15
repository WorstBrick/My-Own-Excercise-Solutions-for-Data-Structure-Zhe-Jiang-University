#include "MGraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Graph InitGraph(int Nv);
void InsertEdge(Graph G,Edge E);
void BuildGraph(Graph G,int Ne);
bool Floyd(Graph G);
bool EachSorceLongestPath(Graph G,WeightType * Distance);
Vertex FindSuitableSorce(WeightType * Distance);
