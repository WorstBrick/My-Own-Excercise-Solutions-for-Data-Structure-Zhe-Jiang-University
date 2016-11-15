#include "Computer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ComputerSet InitCom(int MaxSize);
void Union(ComputerSet CS,Computers i,Computers j);
Computers Find(ComputerSet CS,Computers i);
bool Check(ComputerSet CS,Computers i,Computers j);
int CountConnectComponent(ComputerSet CS,int MaxSize);
