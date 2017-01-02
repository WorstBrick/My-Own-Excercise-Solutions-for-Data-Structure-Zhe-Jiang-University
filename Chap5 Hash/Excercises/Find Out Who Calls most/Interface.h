#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Position Hash(ElementType Number,HashTable H);
int NextPrime(int N);
HashTable InitHashTable(int TableSize);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
void BuildHashTable(int N,HashTable H);

void ShowMax(HashTable H);
