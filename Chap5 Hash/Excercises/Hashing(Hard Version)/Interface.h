#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Position Hash(Key Data,int TableSize);
void BuildWorkSpace(ElementType Buffer[],int TableSize,int * UnShiftLimit,int * ShiftLimit);
void ReversedHash(ElementType Buffer[],int TableSize,int UnShiftLimit,int ShiftLimit);
void UpDateD(ElementType Buffer[],Position InfluencePoint,Position j,int ShiftLimit);
