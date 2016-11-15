#include "Interface.h"

int main(void)
{
    int Size,times,i;
    char ch;
    int flag;
    scanf("%d %d",&times,&Size);
    Stack * S=CreateStack(Size);

    for (i=0;i<times;i++)
    {
        fflush(stdin);
        flag=1;
        S->Rear=-1;
        while ((ch=getchar())!='\n')
        {
            if (ch=='S')
                Push(ch,S);
            else if (ch=='X' && Pop(S)==false)
            {
                flag=0;
                break;
            }

        }
        if (IsEmpty(S) && flag)
            printf("Yes\n");
        else
            printf("No\n");
    }



    return 0;
}

