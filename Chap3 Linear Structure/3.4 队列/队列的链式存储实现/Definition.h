#include <stdbool>
#include <stdio.h>

//具体的数据集合的实现
typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;

//操作集的接口
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);
