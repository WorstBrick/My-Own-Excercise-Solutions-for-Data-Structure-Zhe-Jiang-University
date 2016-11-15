#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

ElementType Find(List L,int m)
{
    int cnt=0;
    PtrToNode tmp;

    for (tmp=L->Next;tmp!=NULL;tmp=tmp->Next)
        cnt++;
    if ((cnt=cnt+1-m)<=0)
        return ERROR;
    int number=1;
    for (tmp=L->Next;number<cnt;number++)
        tmp=tmp->Next;
    return tmp->Data;
}
