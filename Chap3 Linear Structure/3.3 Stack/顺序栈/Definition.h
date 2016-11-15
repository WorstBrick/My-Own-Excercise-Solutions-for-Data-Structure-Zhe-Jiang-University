#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Data.h"

//相应的操作集的接口
Stack CreateStack(int);
bool Push(Stack,ElementType);
bool IsFull(Stack S);
bool IsEmpty(Stack);
ElementType Pop(Stack);
