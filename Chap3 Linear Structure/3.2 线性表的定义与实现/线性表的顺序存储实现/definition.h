#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10
typedef int ElemenType;
typedef int Position;
typedef struct LNode * PtrToLNode;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;


/*线性表的操作集*/
List MakeEmpty(void);
ElementType FindKth(List,int);
Position Find(List,ElemenType);
bool Insert(List,ElemenType,int);
bool Delete(List,int);
int Length(List);
