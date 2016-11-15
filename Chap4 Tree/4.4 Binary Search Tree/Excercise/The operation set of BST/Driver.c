#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
Position Find( BinTree BST, ElementType X )
{
    Position T=BST;

    while (T && T->Data!=X)
    {
        if (X<T->Data)
            T=T->Left;
        else
            T=T->Right;
    }

    return T;
}

Position FindMin( BinTree BST )
{
    if (!BST)
        return BST;
    else
    {
        Position T=BST;
        while (T->Left)
            T=T->Left;

        return T;
    }
}

Position FindMax( BinTree BST )
{
    if (!BST)
        return BST;
    else
    {
        Position T=BST;
        while (T->Right)
            T=T->Right;

        return T;
    }
}

static Position NewNode(ElementType X)
{
    Position T=(Position)malloc(sizeof(*T));
    T->Data=X;
    T->Left=T->Right=NULL;

    return T;
}
BinTree Insert( BinTree BST, ElementType X )
{
    if (!BST)
    {
        BST=NewNode(X);
        return BST;
    }
    else
    {
        Position T=BST;
        while (T->Data!=X)
        {
            if (X<T->Data)
            {
                if (T->Left)
                    T=T->Left;
                else
                {
                    T->Left=NewNode(X);
                    break;
                }
            }
            else
            {
                if (T->Right)
                    T=T->Right;
                else
                {
                    T->Right=NewNode(X);
                    break;
                }
            }
        }
        return BST;
    }
}


BinTree Delete( BinTree BST, ElementType X )
{
    if (!BST)
    {
        puts("Not Found");
        return BST;
    }
    else
    {
        if (X<BST->Data)
            BST->Left=Delete(BST->Left,X);
        else if (X>BST->Data)
            BST->Right=Delete(BST->Right,X);
        else
        {
            Position Tmp;
            if (!(BST->Left) && !(BST->Right))
            {
                free(BST);
                return NULL;
            }
            else if (BST->Left && BST->Right)
            {
                Tmp=FindMax(BST->Left);
                BST->Data=Tmp->Data;
                BST->Left=Delete(BST->Left,Tmp->Data);
            }
            else
            {
                if (BST->Left)
                {
                    Tmp=BST->Left;
                    free(BST);
                    return Tmp;
                }
                if (BST->Right)
                {
                    Tmp=BST->Right;
                    free(BST);
                    return Tmp;
                }
            }
        }
        return BST;
    }
}



