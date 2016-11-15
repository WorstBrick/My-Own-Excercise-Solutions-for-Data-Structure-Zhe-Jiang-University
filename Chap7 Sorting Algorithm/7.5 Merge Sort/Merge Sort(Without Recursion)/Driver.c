#include "Interface.h"

int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    MergeSort(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
