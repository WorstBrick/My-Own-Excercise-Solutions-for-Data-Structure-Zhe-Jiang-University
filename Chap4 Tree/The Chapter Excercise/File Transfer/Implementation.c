#include "Interface.h"


ComputerSet InitCom(int MaxSize)
{
    ComputerSet CS=(ComputerSet)malloc((MaxSize)*sizeof(Computers));
    int i;

    for (i=0;i<MaxSize;i++)
        CS[i]=-1;

    return CS;
}

Computers Find(ComputerSet CS,Computers i)
{
    if (CS[i]<0)
        return i;
    else
        return (CS[i]=Find(CS,CS[i]));
}


void Union(ComputerSet CS,Computers i,Computers j)
{
    Computers S1=Find(CS,i),S2=Find(CS,j);

    if (CS[S1]<CS[S2])
    {
        CS[S1]+=CS[S2];
        CS[S2]=S1;
    }
    else
    {
        CS[S2]+=CS[S1];
        CS[S1]=S2;
    }

}

bool Check(ComputerSet CS,Computers i,Computers j)
{
    return (Find(CS,i)==Find(CS,j));
}


int CountConnectComponent(ComputerSet CS,int MaxSize)
{
    int cnt=0,i;

    for (i=0;i<MaxSize;i++)
    {
        if (CS[i]<0)
            cnt++;
    }

    return cnt;
}
