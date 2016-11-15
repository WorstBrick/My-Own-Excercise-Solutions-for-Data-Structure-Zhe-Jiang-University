#include "interface.h"

void moveL(int list[],int n,int m)
{
    int temp[m];
    int i,j;
    int addition=n-m+1;

    for (i=n-1,j=0;j<m;i--,j++)
        temp[j]=list[i];

    for (i=n-1;i-m>=0;i--)
        list[i]=list[i-m];

    for (j=0;j<m;j++,i--)
        list[i]=temp[j];

}
