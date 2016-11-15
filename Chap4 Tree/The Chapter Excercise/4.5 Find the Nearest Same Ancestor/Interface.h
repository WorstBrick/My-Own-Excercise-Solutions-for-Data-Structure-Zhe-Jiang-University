#include "BTree.h"
#include <stdlib.h>
#include <stdio.h>

BTree InitBTree(int MaxSize);
void Insert(BTree BT);
Position CommonAncestor(Position i,Position j);
