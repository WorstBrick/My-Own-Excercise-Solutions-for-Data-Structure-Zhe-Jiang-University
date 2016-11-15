#include "Item.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#define ERROR 10

Stack CreatStack(int Size);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
int Pop(Stack S);
bool Push(int tag,Stack S);
