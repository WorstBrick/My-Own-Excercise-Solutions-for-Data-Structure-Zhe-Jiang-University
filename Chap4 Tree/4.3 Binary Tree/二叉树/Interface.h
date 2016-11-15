#include "BTree.h"
#include <stdio.h>
#define NOINFO 0
#include <stdlib.h>

bool IsEmpty(BinTree BT);
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void InorderTraversal2(BinTree BT);
void LevelorderTraversal(BinTree BT);
void OutputLeaves(BinTree BT);
int GetHeight(BinTree BT);
BinTree CreateBinTree(void);
BinTree CreateBinTreeInRecursion(void);
