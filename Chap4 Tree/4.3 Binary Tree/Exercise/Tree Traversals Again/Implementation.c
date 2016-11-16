#include "Interface.h"

Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof(*S));
    S->MaxSize=MaxSize;
    S->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    S->Rear=0;

    return S;
}


bool IsFull(Stack S)
{
    return (S->Rear==S->MaxSize);
}

bool Push(Stack S,ElementType X)
{
    if (IsFull(S))
        return false;
    else
    {
        S->Data[(S->Rear)++]=X;
        return true;
    }
}


bool IsEmpty(Stack S)
{
    return (S->Rear==0);
}


ElementType Pop(Stack S)
{
    if (IsEmpty(S))
        return ERROR;
    else
        return (S->Data[--(S->Rear)]);
}

void CreatePreAndIn(TreeNode PreOrder[],TreeNode InOrder[],int N)
{
    Stack S=CreateStack(N);
    char Buf[8];
    int i;
    Position j=0,k=0;

    getchar();
    for (i=0;i<2*N;i++)
    {
        fgets(Buf,8,stdin);
        switch(Buf[1])
        {
            case 'u':
                PreOrder[j]=atoi(Buf+5);
                Push(S,PreOrder[j]);
                j++;
                break;
            case 'o':
                InOrder[k++]=Pop(S);
                break;
        }
    }
}

static Position FindRootIndex(TreeNode InOrder[],TreeNode Root,int N)
{
    Position i;

    for (i=0;i<N && InOrder[i]!=Root;i++);

    return i;
}

void CreatePostOrder(TreeNode PreOrder[],TreeNode InOrder[],TreeNode PostOrder[],int N)
{
    if (N>0)
    {
        PostOrder[N-1]=PreOrder[0];
        int LeftScale=FindRootIndex(InOrder,PreOrder[0],N);
        int RightScale=N-LeftScale-1;
        CreatePostOrder(PreOrder+1,InOrder,PostOrder,LeftScale);
        CreatePostOrder(PreOrder+LeftScale+1,InOrder+LeftScale+1,PostOrder+LeftScale,RightScale);
    }
}

void ShowSequence(TreeNode PostOrder[],int N)
{
    int i;

    printf("%d",PostOrder[0]);
    for (i=1;i<N;i++)
        printf(" %d",PostOrder[i]);
}
