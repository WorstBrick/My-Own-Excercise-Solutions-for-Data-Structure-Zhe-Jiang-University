#include "Interface.h"

int main(void)
{
    Stack S=CreatStack(20);
    char ch;
    int STmp,Tmp,Tag;

    while ((ch=getchar())!='\n')
    {
        if (isdigit(ch))
            printf(" %c",ch);
        else
        {
            if (IsEmpty(S))
            {
                 switch (ch)
                {
                case '+':
                    Push(1,S);
                    break;
                case '-':
                    Push(-1,S);
                    break;
                case '*':
                    Push(2,S);
                    break;
                case '/':
                    Push(-2,S);
                    break;
                case '(':
                    Push(0,S);
                    break;
                }
            }
            else
            {
                if (ch==')')
                {
                    while (((Tag=Pop(S))!=0) && !IsEmpty(S))
                    {

                        switch (Tag)
                        {
                            case 1:
                                printf(" +");
                                break;
                            case -1:
                                printf(" -");
                                break;
                            case 2:
                                printf(" *");
                                break;
                            case -2:
                                printf(" /");
                                break;
                        }
                    }
                    continue;
                }
                STmp=(S->Data)[S->Rear];
                STmp*=STmp;
                switch (ch)
                {
                    case '+':
                        Tmp=1;
                        break;
                    case '-':
                        Tmp=-1;
                        break;
                    case '*':
                        Tmp=2;
                        break;
                    case '/':
                        Tmp=-2;
                        break;
                    case '(':
                        Tmp=0;
                        break;
                }
                while (Tmp && Tmp*Tmp<=STmp && !IsEmpty(S))
                {
                    Tag=Pop(S);
                    switch (Tag)
                    {
                        case 1:
                            printf(" +");
                            break;
                        case -1:
                            printf(" -");
                            break;
                        case 2:
                            printf(" *");
                            break;
                        case -2:
                            printf(" /");
                            break;
                    }
                    if (!IsEmpty(S))
                    {
                        STmp=(S->Data)[S->Rear];
                        STmp*=STmp;
                    }
                }
                if (Tmp*Tmp>STmp || !Tmp || IsEmpty(S))
                    Push(Tmp,S);
            }
        }
    }
    while (!IsEmpty(S))
    {
        switch ((Tag=Pop(S)))
        {
            case 1:
                printf(" +");
                break;
            case -1:
                printf(" -");
                break;
            case 2:
                printf(" *");
                break;
            case -2:
                printf(" /");
                break;
        }
    }

    return 0;
}
