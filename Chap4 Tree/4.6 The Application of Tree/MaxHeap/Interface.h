#include "MaxHeap.h"
MaxHeap CreateHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool Insert(MaxHeap H,ElementType X);
bool IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);

void PercDown(MaxHeap H,int p);//下滤函数,将H中以H->Data[p]为根的子堆调整为最大堆
void BuildHeap(MaxHeap H);

//自己写的一个下滤函数
void MyPercDown(MaxHeap H);
