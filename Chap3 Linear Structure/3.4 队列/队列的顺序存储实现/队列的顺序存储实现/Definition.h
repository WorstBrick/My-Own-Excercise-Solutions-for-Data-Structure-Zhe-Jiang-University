#include <stdlib.h>
#include <stdbool.h>

//���ݼ��ϵľ���ʵ��
typedef int ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;


//��Ӧ�Ĳ������Ľӿ�
Queue CreateQueue(int);
bool IsFull(Queue);
bool AddQ(Queue,ElementType);
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);
