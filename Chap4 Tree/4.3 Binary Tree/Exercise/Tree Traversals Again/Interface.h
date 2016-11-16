#include "Item.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define ERROR -1

//对栈进行操作的接口
Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
bool Push(Stack S,ElementType X);
ElementType Pop(Stack S);

void CreatePreAndIn(TreeNode PreOrder[],TreeNode InOrder[],int N);
void CreatePostOrder(TreeNode PreOrder[],TreeNode InOrder[],TreeNode PostOrder[],int N);
void ShowSequence(TreeNode PostOrder[],int N);
