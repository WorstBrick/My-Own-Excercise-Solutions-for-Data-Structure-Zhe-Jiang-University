#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1,List L2)
{
    List L3=(List)malloc(sizeof (*L3));
    List tmp1=L1->Next;
    List tmp2=L2->Next;
    List tmp3=L3;

    while (tmp1 && tmp2)
    {
        if (tmp1->Data < tmp2->Data)
        {
            tmp3->Next=tmp1;
            tmp1=tmp1->Next;
            tmp3=tmp3->Next;
        }
        else if (tmp1->Data > tmp2->Data)
        {
            tmp3->Next=tmp2;
            tmp2=tmp2->Next;
            tmp3=tmp3->Next;
        }
        else
        {
            tmp3->Next=tmp1;
            tmp1=tmp1->Next;
            tmp2=tmp2->Next;
            tmp3=tmp3->Next;
        }
    }
    for (;tmp1;tmp1=tmp1->Next)
    {
        tmp3->Next=tmp1;
        tmp3=tmp3->Next;
    }
    for (;tmp2;tmp2=tmp2->Next)
    {
        tmp3->Next=tmp2;
        tmp3=tmp3->Next;
    }
    tmp3->Next=NULL;
    L1->Next=NULL;
    L2->Next=NULL;

    return L3;
}
