#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#define RADIX 10
#define MAXDIGIT 2

Bucket InitBucket(int MaxSize);
int GetDigit(ElementType X,int D);
void RadixSort(ElementType A[],int N);
