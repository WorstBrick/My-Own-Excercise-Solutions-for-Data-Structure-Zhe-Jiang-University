#include <stdbool.h>

typedef int ElementType;
typedef struct SNode * PtrToSNode;
struct SNode{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack(int);
bool Push(Stack,ElementType);
bool IsFull(Stack S);
bool IsEmpty(Stack);
ElementType Pop(Stack);
