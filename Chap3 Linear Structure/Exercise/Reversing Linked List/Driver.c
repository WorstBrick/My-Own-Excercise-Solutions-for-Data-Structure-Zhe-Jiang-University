#include "Interface.h"

int main(void)
{
    int N,K;
    scanf("%d %d",&N,&K);

    List L=CreateList(N);
    ShowList(L->Next);
    printf("\n\n");
    L=ReverseK(L->Next,N,K);
    ShowList(L);

    return 0;
}
