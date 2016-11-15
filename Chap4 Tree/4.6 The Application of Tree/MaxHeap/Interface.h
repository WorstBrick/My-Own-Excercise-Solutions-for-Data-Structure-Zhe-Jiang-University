#include "MaxHeap.h"
MaxHeap CreateHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool Insert(MaxHeap H,ElementType X);
bool IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);

void PercDown(MaxHeap H,int p);//���˺���,��H����H->Data[p]Ϊ�����Ӷѵ���Ϊ����
void BuildHeap(MaxHeap H);

//�Լ�д��һ�����˺���
void MyPercDown(MaxHeap H);
