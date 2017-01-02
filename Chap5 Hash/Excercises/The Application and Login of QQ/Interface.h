#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define DIGITS 17

int Hash(ElementType Key,HashTable H);
int NextPrime(int TableSize);
HashTable InitHashTable(int TableSize);
Position Find(ElementType Key,HashTable H);
bool Insert(ElementType Key,char PassWord[],HashTable H);
ElementType MakeKey(char RawKey[]);
void AppAndLog(int N,HashTable H);
