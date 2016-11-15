#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Position;

//��������йص�
void AdjustArrayToHeap(ElementType A[],int N);
void HeapSortModified(ElementType A[],ElementType Semi[],int N);

//������йص�
int FindInsertTimes(ElementType Semi[],int N);
void InsertSortSomeTimes(ElementType Copy[],int Times);
void InsertOne(ElementType Copy[],Position Index);
bool CheckSequence(ElementType Semi[],ElementType Copy[],int N);

void ShowSequence(ElementType A[],int N);
