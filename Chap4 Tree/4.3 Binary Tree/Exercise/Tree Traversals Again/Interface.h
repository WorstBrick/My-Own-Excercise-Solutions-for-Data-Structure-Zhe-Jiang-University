#include "Item.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//��ջ���в����Ľӿ�
Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
bool Push(Stack S,BinTree X);
BinTree Pop(Stack S);

//�������еĲ���
BinTree CreateTree(void);
void PostorderTraversal(BinTree BT,Stack S);
