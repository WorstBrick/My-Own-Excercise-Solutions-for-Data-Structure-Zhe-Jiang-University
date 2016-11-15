#include "Interface.h"

int main(void)
{
    int Num,i;
    scanf("%d",&Num);

    int * List=(int *)malloc(Num*sizeof(int));
    for (i=0;i<Num;i++)
        scanf("%d",&List[i]);

    //printf("%d\n",MaxSubsequence(List,Num));
    ShowMaxSubsequence(List,Num);

    return 0;
}
