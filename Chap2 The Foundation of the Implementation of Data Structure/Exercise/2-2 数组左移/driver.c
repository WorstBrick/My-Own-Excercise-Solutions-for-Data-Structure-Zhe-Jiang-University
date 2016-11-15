#include "interface.h"
#include <stdio.h>
#define SIZE 9
int main(void)
{
    int numbers[SIZE]={1,2,3,4,5,6,7,8,9};
    int i;

    moveL(numbers,SIZE,4);

    for (i=0;i<SIZE;i++)
        printf("%-3d",numbers[i]);

    return 0;
}
