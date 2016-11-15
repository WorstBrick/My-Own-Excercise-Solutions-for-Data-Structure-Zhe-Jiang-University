#include <stdlib.h>
#include <stdbool.h>

//数据集合的具体实现
typedef int ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;


//相应的操作集的接口
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);
