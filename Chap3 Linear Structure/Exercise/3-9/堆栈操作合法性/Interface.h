#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Item.h"

Stack * CreateStack(int Size);
bool IsEmpty(Stack * S);
bool Push(char ch,Stack * S);
bool Pop(Stack * S);
bool IsFull(Stack * S);
