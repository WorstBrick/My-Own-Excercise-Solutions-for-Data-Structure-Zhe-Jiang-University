#include "Item.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//对栈进行操作的接口
Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
bool Push(Stack S,BinTree X);
BinTree Pop(Stack S);

//对树进行的操作
BinTree CreateTree(void);
void PostorderTraversal(BinTree BT,Stack S);
