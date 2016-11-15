#include "interface.h"
#define SIZE 9
#include <stdio.h>

int main(void)
{
    EleType list[SIZE]={6,5,9,8,2,1,7,3,4};
    int K=(SIZE/2)+1;

    printf("The median is %d\n",FindKth(list,SIZE,K));

    return 0;
}
