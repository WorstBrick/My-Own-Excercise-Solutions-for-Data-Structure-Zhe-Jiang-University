#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//栈的操作集
Stack InitStack(int MaxNum);
bool IsFull(Stack S);
bool Push(Stack S,SElement X);
bool IsEmpty(Stack S);
SElement Pop(Stack S);
SElement NewEndPoints(Position Left,Position Right);
//归并排序
void MergeOperation(ElementType A[],ElementType Tmp[],Position LeftStart,Position RightStart,Position RightEnd);
void CoreSort(ElementType A[],ElementType Tmp[],Position LeftStart,Position RightEnd);
void MergeSort(ElementType A[],int N);
