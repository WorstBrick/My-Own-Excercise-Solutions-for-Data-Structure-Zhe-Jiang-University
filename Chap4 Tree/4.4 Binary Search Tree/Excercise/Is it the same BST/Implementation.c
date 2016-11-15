#include "Interface.h"


static BSTree CreateTNode(ElementType Data)
{
    BSTree Node=(BSTree)malloc(sizeof(*Node));
    Node->Data=Data;
    Node->Left=NULL;
    Node->Right=NULL;

    return Node;
}

BSTree CreateBSTree(int N)
{
    ElementType Data;
    scanf("%d",&Data);
    BSTree BST=CreateTNode(Data);
    BSTree T;
    int i;

    for (i=1;i<N;i++)
    {

        T=BST;
        scanf("%d",&Data);
        while (T->Left || T->Right)
        {
            if (Data < T->Data)
            {
                if (T->Left)
                    T=T->Left;
                else
                    break;
            }
            else
            {
                if (T->Right)
                    T=T->Right;
                else
                    break;
            }
        }
        if (Data < T->Data)
            T->Left=CreateTNode(Data);
        else
            T->Right=CreateTNode(Data);
    }

    return BST;
}

bool CompareBST(BSTree T1,BSTree T2)
{
    if (!T1 && !T2)
        return true;
    else if ((T1 && !T2)||(!T1 && T2))
        return false;
    if (T1->Data !=T2->Data)
        return false;
    else
    {
        if (CompareBST(T1->Left,T2->Left) && CompareBST(T1->Right,T2->Right))
            return true;
        else
            return false;
    }
}
