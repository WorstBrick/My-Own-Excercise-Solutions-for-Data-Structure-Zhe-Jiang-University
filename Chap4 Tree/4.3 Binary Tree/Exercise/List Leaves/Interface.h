#include "Item.h"
#include <stdio.h>
#include <stdlib.h>

Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);

FakeTree InitTree(int N);
void ReadNode(FakeTree FT,int N);
