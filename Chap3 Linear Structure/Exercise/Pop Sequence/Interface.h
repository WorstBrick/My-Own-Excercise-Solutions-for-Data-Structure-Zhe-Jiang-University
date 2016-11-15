#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ERROR -1

Stack CreateStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S,ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);
void CleanStack(Stack S);


bool IsPopSequence(int N,Stack S);
