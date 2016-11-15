#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree InitTree(int quant);
Position FillTNode(BinTree BT,int quant)
Position Find(BinTree BT,int quant,ElementType X);
void JudgeIsom(BinTree BT1,BinTree BT2,Position root1,Position root2);
