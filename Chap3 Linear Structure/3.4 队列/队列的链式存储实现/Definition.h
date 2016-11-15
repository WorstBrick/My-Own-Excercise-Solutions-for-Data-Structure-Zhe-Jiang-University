#include <stdbool>
#include <stdio.h>

//��������ݼ��ϵ�ʵ��
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

//�������Ľӿ�
bool IsEmpty(Queue);
ElementType DeleteQ(Queue);
