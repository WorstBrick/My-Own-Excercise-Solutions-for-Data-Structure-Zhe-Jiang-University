#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define NOPLACE -1

int NextPrime(int TableSize);
HashTable InitHashTable(int TableSize);
Position Hash(ElementType Key,HashTable H);
Position Find(ElementType Key,HashTable H);
void InsertModifed(ElementType Key,HashTable H);
