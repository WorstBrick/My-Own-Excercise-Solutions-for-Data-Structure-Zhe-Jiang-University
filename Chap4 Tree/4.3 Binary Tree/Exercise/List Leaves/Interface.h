#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#define NOSON -3
#define ERROR -1

Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);

FakeTree InitTree(int N);
void ReadNode(FakeTree FT,int N);
Node FindRoot(FakeTree FT,int N);
void ListLeaves(FakeTree FT,int N);
