#include "MinHeap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

MinHeap InitHeap(int MaxSize);
bool IsFull(MinHeap H);
bool Insert(MinHeap H,ElementType X);
bool ShowPath(MinHeap H,int i);
