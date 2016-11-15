#define ERROR -1
#include <stdlib.h>
typedef int ElementType;
typedef struct LNode * PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

int Length(List L);
ElementType FindKth(List,int);
Position Find(List,ElemenType);
List Insert_vCasual(List L,ElemenType X,int i);
bool Insert(List,ElemenType,int);
bool Delete(List,int);
