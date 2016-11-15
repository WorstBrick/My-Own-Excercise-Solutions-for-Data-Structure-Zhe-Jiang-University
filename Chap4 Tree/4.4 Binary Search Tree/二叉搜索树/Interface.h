#include "BSTree.h"
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
Position FindRecur(BinTree BST,ElementType X);
Position Find(BinTree BST,ElementType X);
Position FindMin(BinTree BST);
Position FindMinRecur(BinTree BST);
Position FindMax(BinTree BST);
Position FindMaxRecur(BinTree BST);
BinTree Insert(BinTree BST,ElementType X);
BinTree Delete(BinTree BST,ElementType X);
