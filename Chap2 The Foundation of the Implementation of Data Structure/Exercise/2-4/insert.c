#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

List Insert(List L, ElementType X);

int main(void)
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

List Insert(List L, ElementType X)
{
    PtrToNode temp=L;
    PtrToNode New;
    while (temp->Next!=NULL && temp->Next->Data<=X)
        temp=temp->Next;
    New=(PtrToNode)malloc(sizeof *New);
    New->Data=X;
    New->Next=(temp->Next? temp->Next:NULL);
    temp->Next=New;

    return L;
}
