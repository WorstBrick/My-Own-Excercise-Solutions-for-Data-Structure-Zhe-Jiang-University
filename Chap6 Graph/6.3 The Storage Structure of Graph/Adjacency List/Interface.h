#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//ͼ�Ĳ�����
LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph,Edge E);
LGraph BuildGraph(void);
void Visit(Vertex V);
void DFS(LGraph G,Vertex V,void(*Visit)(Vertex));
