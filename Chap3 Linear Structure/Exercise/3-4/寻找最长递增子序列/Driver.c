#include "Interface.h"

int main(void)
{
    int *List;
    int Size;
    int i;

    scanf("%d",&Size);
    List=(int *)malloc(Size * sizeof(int));
    for (i=0;i<Size;i++)
        scanf("%d",&List[i]);

    Subsequece(List,Size);

    return 0;
}
