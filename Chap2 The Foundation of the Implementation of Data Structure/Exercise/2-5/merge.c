#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType data;
    PtrToNode   next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
static PtrToNode NodeMerge(PtrToNode,PtrToNode);
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

List Merge( List L1, List L2 )
{
    PtrToNode ptrL1=L1->Next;
    PtrToNode ptrL2=L2->Next;
    PtrToNode temp;
    ElementType num;

    while (ptrL2->Next!=NULL && ptrL1->Next!=NULL)
    {
        if (ptrL1->Data > ptrL2->Data)
        {
            num=ptrL1->Data;
            ptrL1->Data=ptrL2->Data;
            ptrL2->Data=num;
        }
        else
        {
            if (ptrL2->Data > ptrL1->Next->Data)
                ptrL1=ptrL1->Next;
            else
            {
                temp=ptrL2->Next;
                ptrL2->Next=ptrL1->Next;
                ptrL1->Next=ptrL2;
                ptrL2=temp;
                ptrL1=ptrL1->Next;
            }
        }
    }
    if (!(ptrL1->Next))
        ptrL1->Next=ptrL2;
    if (!(ptrL2->Next))
        ptrL2->Next=ptrL1;
    return L1->Next;
}

temp=ptrL2->Next;
            ptrL2->Next=ptrL1;
            L1=ptrL2;
            ptrL2=temp;
            ptrL1=ptrL1->Next;
