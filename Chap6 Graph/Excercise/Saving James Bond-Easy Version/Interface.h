#include "Item.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define END 0
//���нӿ�
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);


//ͼ�Ľӿ�
Graph InitGraph(int N);
void InsertVer(Graph G,Vertex V1,Vertex V2);
void BuildGraph(Graph G,double D);
bool BFS(Graph G);
