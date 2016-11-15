#include "Interface.h"

void InorderTraversal(BinTree BT)
{
    InorderTraversal(BT->Left);
    printf("%d\n",BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT)
{
    printf("%d\n",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT)
{
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf("%d\n",BT->Data);
}

void InorderTraversal2(BinTree BT)
{
    BinTree T;
    Stack S=CreateStack();

    T=BT;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S,T);
            T=T->Left;
        }
        T=Pop(S);
        printf("%d",T->Data);
        T=T->Right;
    }
}

void LevelorderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;

    if (!BT)
        return;

    Q=CreateQueue();
    Add(Q,BT);
    while (!IsEmpty(Q))
    {
        T=DeleteQ(Q);
        printf("%d\n",T->Data);
        if (T->Left)
            Add(Q,T->Left);
        if (T->Right)
            Add(Q,T->Right);
    }
}

void OutputLeaves(BinTree BT)
{
    if (BT)
    {
        if (!BT->Left && !BT->Right)
            printf("%d\n",BT->Data);
        OutputLeaves(BT->Left);
        OutputLeaves(BT->Right);
    }
}


int GetHeight(BinTree BT)
{
    int HL,HR,MaxH;

    if (BT)
    {
        HL=GetHeight(BT->Left);
        HR=GetHeight(BT->Left);
        MaxH=(HL>HR? HL : HR);
        return MaxH;
    }
    return 0;
}


BinTree CreateBinTree(void)
{
    ElementType Data;
    BinTree BT,T;
    Queue Q=CreateQueue();

    scanf("%d",&Data);
    if (Data!=NOINFO)
    {
        BT=(BinTree)malloc(sizeof(*BT));
        BT->Data=Data;
        BT->Left=BT->Right=NULL;
        AddQ(Q,BT);
    }
    else
        return NULL;

    while (!IsEmpty(Q))
    {
        T=DeleteQ(Q);
        scanf("%d",&Data);
        if (Data==NOINFO)
            T->Left=NULL;
        else
        {
            T->Left=(BinTree)malloc(sizeof(struct TNode));
            T->Left->Data=Data;
            T->Left->Left=T->Left->Right=NULL;
            AddQ(Q,T->Left);
        }
        scanf("%d",&Data);
        if (Data==NOINFO)
            T->Right=NULL;
        else
        {
            T->Right=(BinTree)malloc(sizeof(struct TNode));
            T->Right->Data=Data;
            T->Right->Left=T->Right->Right=NULL;
            AddQ(Q,T->Right);
        }
    }

    return BT;
}


/*假设二叉树为：
                                        a
                              b                 c
                                   d                 e

         因为程序中要知道叶子结点（终点），所以要将上面的二叉树变成扩展二叉树 (把叶子结点的孩子补成0,即NOINFO 用作标记),  扩展后就变成了：
                                       a
                            b                    c
                       0        d          0       e
                              0    0             0    0

          那么，在输入的时候，需要输入: ab0d00c0e00      (注意，输入后，按enter键即可)   ，程序如下：*/
BinTree CreateBinTreeInRecursion(void)//用递归的方式实现,而且是前序创建
{
	ElementType Data;
	scanf("%d",&Data);
	if(Data==NOINFO)
		return NULL;
	else
	{
		BinTree BT=(BinTree)malloc(sizeof(*BT));
		BT->Data =Data;
		createBiTree(BT->Left);
		createBiTree(BT->Right);
	}

	return BT;
}

Position FindRecur(BinTree BST,ElementType X)
{
    if (BST==NULL)
        return NULL;

    if (BST->Data >X)
        return Find(BST->Left,X);
    else if (BST->Data <X)
        return Find(BST->Right,X);
    else
        return BST;
}


Position Find(BinTree BST,ElementType X)
{
    if (!BST)
        return NULL;

    BinTree T=BST;
    while (T)
    {
        if (T->Data > X)
            T=T->Left;
        else if (T->Data <X)
            T=T->Right;
        else
            return T;
    }

    return T;
}

Position FindMinRecur(BinTree BST)
{
    if (!BST || !(BST->Left))
        return BST;
    return FindMinRecur(BST->Left);
}
Position FindMin(BinTree BST)
{
    if (BST)
        while (BST->Left)
            BST=BST->Left;

    return BST;
}

Position FindMax(BinTree BST)
{
    if (BST)
        while (BST->Right)
            BST=BST->Right;

    return BST;
}


Position FindMaxRecur(BinTree BST)
{
    if (!BST || !(BST->Right))
        return BST;
    return FindMaxRecur(BST->Right);
}

BinTree Insert(BinTree BST,ElementType X)
{
    if (!BST)
    {
        BST=(BinTree)malloc(sizeof (*BST))
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }
    Position T=BST;

    while(T->Left && T->Right)
    {
        if (X < T->Data)
            T=T->Left;
        else if (X >T->Data)
            T=T->Right;
        else
            return BST;
    }

    Position NEW=(Position)malloc(sizeof (*NEW));
    NEW->Data=X;
    NEW->Left=NEW->Right=NULL;
    if (X < T->Data)
        T->Left=NEW;
    else if (X > T->Data)
        T->Right=NEW;

    return BST;
}


BinTree Delete(BinTree BST,ElementType X)
{
    Position Tmp;

    if (!BST)
        printf("Can't find the element\n");
    else
    {
        if (X < BST->Data)
            BST->Left=Delete(BST->Left,X);
        else if (X >BST->Data)
            BST->Right=Delete(BST->Right,X);
        else
        {
            if (BST->left && BST->Right)
            {
                Tmp=FindMin(BST->Right);
                BST->Data=Tmp->Data;
                BST->Right=Delete(BST->Right,BST->Data);
            }
            else
            {
                Tmp=BST;
                if (!BST->Left)
                    BST=BST->Right;
                else if (!BST->Right)
                    BST=BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}
