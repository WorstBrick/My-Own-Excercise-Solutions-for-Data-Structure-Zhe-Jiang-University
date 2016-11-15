#include "Interface.h"

void Subsequece(int * List,int Size)
{
    int cnt=0;
    int Max=0;
    int i=0;
    int TmpHeadI,SubHeadI;
    int SubEndI=0;

    while (i<Size-1)
    {
        for (TmpHeadI=i;List[i+1]>List[i] && i<Size-1;i++)
            cnt++;
        if (cnt>Max)
        {
            Max=cnt;
            cnt=0;
            SubHeadI=TmpHeadI;
            SubEndI=i;
        }
        i++;
    }
    if (!SubEndI)
    {
        printf("No such sequence./n");
        exit(0);
    }
    SubEndI++;
    for (i=SubHeadI;i<SubEndI;i++)
        printf("%d ",List[i]);

}
