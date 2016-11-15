#include "Item.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define UNMEANNING -2
#define NOSON -1

//AVL���Ĳ�����
AvlTree InitAvlTree(ElementType X);
int GetHeight(AvlTree T);
AvlTree RRRotate(AvlTree T);
AvlTree LLRotate(AvlTree T);
AvlTree RLRotate(AvlTree T);
AvlTree LRRotate(AvlTree T);
AvlTree Insert(AvlTree T,ElementType X);
void AvlVisit(PtrToAVNode T);
void AvlInorder(AvlTree T);


//CBS���Ĳ�����
CBSTree InitCBStree(int N);
void CBSVisit(CBSTree CT,Position j);
void CBSInorder(CBSTree CT,Position j);
void CBSLayerOrder(CBSTree CT);
