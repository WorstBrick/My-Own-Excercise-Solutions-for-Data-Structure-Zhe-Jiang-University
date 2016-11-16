#include "Interface.h"

int main(void)
{
    int N;
    scanf("%d",&N);

    TreeNode PreOrder[N];
    TreeNode InOrder[N];
    TreeNode PostOrder[N];

    CreatePreAndIn(PreOrder,InOrder,N);
    CreatePostOrder(PreOrder,InOrder,PostOrder,N);
    ShowSequence(PostOrder,N);

    return 0;
}
