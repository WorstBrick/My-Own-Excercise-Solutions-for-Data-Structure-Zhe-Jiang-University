#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Position;

Position FindReverseIndex(ElementType Semi[],int N);
//�鲢����
void MergeOperationModified(ElementType A[],ElementType Tmp[],Position Leftstart,Position RightStart,Position RightEnd);
void CoreMerge(ElementType A[],ElementType Tmp[],int Num,int Length);
bool MergeSortUntilEnough(ElementType A[],ElementType Semi[],ElementType Tmp[],int N,int Enough);
bool CheckSequence(ElementType A[],ElementType Semi[],int N);

//��������
void OneInsertion(ElementType Semi[],Position k);
