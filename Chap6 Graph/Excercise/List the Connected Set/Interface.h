#include "Item.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define ERROR -1

//���еĽӿ�
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);

//ͼ�Ľӿ�
Graph InitGraph(int N);
void InsertEdge(Graph G,Edge tmp);
void BuildGraph(Graph G,int E);
void Visit(Vertex V);
void DFS(Graph G,Vertex V);
void BFS(Graph G,Vertex V);
void TravelAll_DFS(Graph G);
void TravelAll_BFS(Graph G);
