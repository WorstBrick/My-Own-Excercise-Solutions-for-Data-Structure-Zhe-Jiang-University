#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define NOINFO 1
#define SIZE 63

Tree NewNode(void);//用于创建节点
void ReadFre(int N);
void CalFre(int N);
bool JudgeHuff(int N);
