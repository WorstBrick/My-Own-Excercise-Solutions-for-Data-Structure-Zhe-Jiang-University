#include "Graph.h"
#include <stdlib.h>

int Prim(MGraph G,LGraph MST);
LGraph InitLGraph(int Nv);
Vertex FindMinDist(MGraph G,WeightType dist[]);
void InsertLGraphEdge(LGraph LG,Edge E);
