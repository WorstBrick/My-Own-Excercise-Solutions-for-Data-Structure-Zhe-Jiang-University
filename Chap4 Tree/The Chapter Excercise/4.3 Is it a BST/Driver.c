#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* �ɲ���ʵ�֣�ϸ�ڲ��� */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */

ElementType FindMin(BinTree T)
{
    while (T->Left)
        T=T->Left;
    return T->Data;
}

ElementType FindMax(BinTree T)
{
    while (T->Right)
        T=T->Right;
    return T->Data;
}

bool IsBST_v1(BinTree T)
{
    if (T==NULL)
        return true;
    else if (!(T->Left) && !(T->Right))
        return true;
    else if (T->Left && !(T->Right) && !(T->Left->Left) && !(T->Left->Right))
        return (T->Data > T->Left->Data);
    else if (T->Right && !(T->Left) && !(T->Right->Left) && !(T->Right->Right))
        return (T->Data < T->Right->Data);
    else if (T->Left && T->Right)
    {
        if (!(T->Left->Left) && !(T->Left->Right) && !(T->Right->Left) && !(T->Right->Right))
            return (T->Data>T->Left->Data && T->Data<T->Right->Data);
        else if (IsBST(T->Left) && IsBST(T->Right))
            return (T->Data>FindMax(T->Left) && T->Data<FindMin(T->Right));
        else
            return false;
    }
}

bool IsBST_v2(BinTree T)
{
    if (T==NULL)
        return true;
    else if (!(T->Left) && !(T->Right))
        return true;
    else if (T->Left && !(T->Right))
    {
        if (IsBST(T->Left))
            return (T->Data>FindMax(T->Left));
        else
            return false;
    }
    else if (T->Right && !(T->Left))
    {
        if (IsBST(T->Right))
            return (T->Data<FindMin(T->Right));
        else
            return false;
    }
    else
    {
        if (IsBST(T->Left) && IsBST(T->Right))
            return (T->Data>FindMax(T->Left) && T->Data<FindMin(T->Right));
        else
            return false;
    }
}

/*�ֳ�NULL,ֻ��һ�����ڵ�, O   ,O  ,   O  ,�Լ�����,һ��6�����
                          /      \    / \
                         O        O  O   O
*/
//�����и��õķ���http://blog.csdn.net/sgbfblog/article/details/7771096
