#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Item.h"

//堆排序所需的操作
Heap InitHeap(int Max);
void HeapInsert(Heap H,ElementType X);
void UpFilt(Heap H,ElementType X);
bool IsEmpty(Heap H);
void DownFilt(Heap H);
ElementType HeapDelete(Heap H);
void HeapSort(ElementType A[],int N);
