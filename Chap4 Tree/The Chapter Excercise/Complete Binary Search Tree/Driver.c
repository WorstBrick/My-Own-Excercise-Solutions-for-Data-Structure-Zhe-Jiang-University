#include "Interface.h"

extern ElementType * SortedBuf;
extern int i;
int main(void)
{
    int N,j;
    scanf("%d",&N);
    CBSTree CT=InitCBStree(N);
    SortedBuf=(ElementType*)malloc(N*sizeof(ElementType));
    i=0;

    ElementType X;
    scanf("%d",&X);
    AvlTree T=InitAvlTree(X);

    for (j=1;j<N;j++)
    {
        scanf("%d",&X);
        T=Insert(T,X);
    }
    AvlInorder(T);

    i=0;
    CBSInorder(CT,1);
    CBSLayerOrder(CT);

    return 0;
}
