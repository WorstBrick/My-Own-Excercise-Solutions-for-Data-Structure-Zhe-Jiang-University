#include "Interface.h"

int main(void)
{
    int MaxSize,cnt;
    char Commands;
    scanf("%d",&MaxSize);
    ComputerSet CS=InitCom(MaxSize);
    Computers i,j;

    while (true)
    {
        fflush(stdin);
        scanf("%c",&Commands);
        if (Commands=='S')
            break;
        scanf("%d %d",&i,&j);
        switch (Commands)
        {
            case 'C':
                if (Check(CS,i-1,j-1))
                    puts("Yes");
                else
                    puts("No");
                break;
            case 'I':
                Union(CS,i-1,j-1);
                break;
            default:
                break;
        }
    }
    cnt=CountConnectComponent(CS,MaxSize);
    if (cnt==1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n",cnt);

    return 0;
}
