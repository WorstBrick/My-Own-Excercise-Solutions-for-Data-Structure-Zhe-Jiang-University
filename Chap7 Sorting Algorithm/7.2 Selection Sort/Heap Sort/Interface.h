#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Item.h"

//����������Ĳ���
Heap InitHeap(int Max);
void HeapInsert(Heap H,ElementType X);
void UpFilt(Heap H,ElementType X);
bool IsEmpty(Heap H);
void DownFilt(Heap H);
ElementType HeapDelete(Heap H);
void HeapSort(ElementType A[],int N);
