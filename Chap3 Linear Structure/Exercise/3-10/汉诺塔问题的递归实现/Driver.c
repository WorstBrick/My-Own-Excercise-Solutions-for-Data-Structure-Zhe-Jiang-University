#include "Interface.h"

int main(void)
{
    char a='a',b='b',c='c';
    int n;

    scanf("%d",&n);
    Hanoi(n,a,b,c);

    return 0;
}
