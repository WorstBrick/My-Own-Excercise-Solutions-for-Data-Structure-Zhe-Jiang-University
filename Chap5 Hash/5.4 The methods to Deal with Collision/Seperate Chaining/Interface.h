#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


HashTable InitHashTable(int TableSize);
int NextPrime(int TableSize);
Position Hash(ElementType Key,HashTable H);
PtrToKNode Find(ElementType Key,HashTable H);
bool Insert(ElementType Key,HashTable H);
bool Delete(ElementType Key,HashTable H);
