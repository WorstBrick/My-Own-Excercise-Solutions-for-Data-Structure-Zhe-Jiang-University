#include "Interface.h"

int main(void)
{
    int N,L;

    scanf("%d %d",&N,&L);
    if (!N)
        return 0;
    BSTree TemplateTree=CreateBSTree(N);
    BSTree T;
    int i;

    for (i=0;i<L;i++)
    {
        fflush(stdin);
        T=CreateBSTree(N);
        if (CompareBST(TemplateTree,T))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
