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

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

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

/* 你的代码将被嵌在这里 */

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
