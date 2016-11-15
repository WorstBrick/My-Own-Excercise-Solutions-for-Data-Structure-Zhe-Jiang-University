#include "Interface.h"

ElementType *Buffer;
int main(void)
{
    char Input[8];
    int N,i;

    scanf("%d",&N);
    Buffer=(ElementType *)malloc((2*N+1)*sizeof(ElementType));
    for (i=0;i<2*N;i++)
    {
        fflush(stdin);
        fgets(Input,7,stdin);
        if (Input[2]=='p')
            Buffer[i]=NONODE;
        else
            Buffer[i]=atoi(&(Input[5]));
    }
    Buffer[i]=NONODE;

    /*for (i=0;i<2*N+1;i++)
        printf("%d ",Buffer[i]);*/
    Stack S=CreateStack(2*N+1);
    BinTree BT=CreateTree();
    PostorderTraversal(BT,S);

    return 0;
}
