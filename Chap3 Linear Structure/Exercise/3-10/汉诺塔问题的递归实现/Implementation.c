#include "Interface.h"

void Hanoi(int n,char a,char b,char c)
{
    if (n>1)
    {
        Hanoi(n-1,a,c,b);
        Hanoi(1,a,b,c);
        Hanoi(n-1,b,a,c);
    }
    if (n==1)
    {
        printf("%c -> %c\n",a,c);
        return;
    }

}
