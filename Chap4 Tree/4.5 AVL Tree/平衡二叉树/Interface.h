#include "AVLTree.h"
#include <stdlib.h>

AVLTree Insert(AVLTree T,ElementType X);
int GetHeight(AVLTree T);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree DoubleLeftRightRoration(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleRightLeftRoration(AVLTree A);
