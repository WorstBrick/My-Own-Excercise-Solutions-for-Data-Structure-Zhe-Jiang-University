#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Data.h"

//��Ӧ�Ĳ������Ľӿ�
Stack CreateStack(int);
bool Push(Stack,ElementType);
bool IsFull(Stack S);
bool IsEmpty(Stack);
ElementType Pop(Stack);
