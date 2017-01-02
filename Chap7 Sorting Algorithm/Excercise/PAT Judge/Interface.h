#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#define RADIX 10
#define NOSOLUTION -2

UserList InitUserList(int MaxNum);
int GetID(char Buf[]);
void BuildUserList(UserList U,int * FullMark,int M,int K);
Table InitTable(int MaxNum);

Bucket InitBucket(int MaxNum);
void FullMarkQuantBucketSort(Table T,UserList U,Bucket B,int N,int K);
void TotalMarkRadixSort(Table T,UserList U,Bucket B,int N);
int GetDigit(int Num,int D);
void ShowRank(Table T,UserList U,int N,int K);
