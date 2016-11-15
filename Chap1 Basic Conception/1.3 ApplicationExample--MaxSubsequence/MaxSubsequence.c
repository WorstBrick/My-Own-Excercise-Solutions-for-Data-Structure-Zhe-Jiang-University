#include "Interface.h"

int MaxSubsequence(int List[],int Num)//ÔÚÏßËã·¨
{
   int Present=0,Max=0;
   int i;

   for (i=0;i<Num;i++)
   {
        Present+=List[i];
        if (Present<0)
        {
            Present=0;
            continue;
        }
        if (Present>Max)
            Max=Present;
   }

   return Max;
}

void ShowMaxSubsequence(int List[],int Num)
{
    int Present=0,Max=0,Start=0,End=Num-1,i;
    int PresentStart=Start,PresentEnd=End;

    for (i=0;i<Num;i++)
    {
        Present+=List[i];
        PresentEnd=i;
        if (Present<0)
        {
            PresentStart=i+1;
            Present=0;
        }
        if (Present>Max)
        {
            Max=Present;
            Start=PresentStart;
            End=PresentEnd;
        }
    }

    if (Max==0)
        printf("%d %d %d",Max,List[0],List[Num-1]);
    else
        printf("%d %d %d",Max,List[Start],List[End]);
}
