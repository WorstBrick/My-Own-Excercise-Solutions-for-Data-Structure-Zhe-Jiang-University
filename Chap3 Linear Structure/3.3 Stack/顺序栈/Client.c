#include "Definition.h"
#include <ctype.h>
#define MAXOP 100
#define INFINITY 1e9
typedef enum {Num,Opr,End} Type;

Type GetOp(char * Expr,int * start,char *str)//为什么用int * 的start?因为这里的start是属于postfixExp()函数的
{
    int i=0;

    while ((str[0]=Expr[(*start)++])==' ');//跳过表达式前的空格

    while (str[i]!=' ' && str[i]!='\0')
        str[++i]=Expr[(*start)++];
    if (str[i]=='\0')
        (*start)--;
    str[i]='\0';

    printf("%s\n",str);
    if (i==0)
        return End;
    else if (isdigit(str[0]) || isdigit(str[1]))
        return Num;
    else
        return Opr;
}

ElementType postfixExp(char * Expr)
{
    Stack S;
    Type T;
    ElementType op1,op2;
    char str[MAXOP];
    int start=0;

    S=CreateStack(MAXOP);

    op1=op2=0.0;
    while ((T=GetOp(Expr,&start,str))!=End)
    {
        if (T==Num)
            Push(S,atof(str));
        else
        {
            if (!IsEmpty(S))
                op2=Pop(S);
            else
                op2=INFINITY;
            switch(str[0])
            {
                case '+':Push(S,op1+op2);break;
                case '*':Push(S,op1*op2);break;
                case '-':Push(S,op1-op2);break;
                case '/':
                    if (op2!=0.0)
                        Push(S,op1/op2);
                    else
                    {
                        printf(("Error:denominator is zero.\n"));
                        op2=INFINITY;
                    }
                    break;
                default:
                    printf("Error:Undefined operator %s.\n",str);
                    op2=INFINITY;
                    break;
            }
            if (op2>=INFINITY)
                break;
        }
    }
    if (op2<INFINITY)
    {
        if (!IsEmpty(S))
            op2=Pop(S);
        else
            op2=INFINITY;
    }
    free(S);

    return op2;
}

int main(void)
{
    char Expr[MAXOP];
    ElementType f;

    gets(Expr);
    f=postfixExp(Expr);
    if (f<INFINITY)
        printf("%.4f\n",f);
    else
        printf("The expression is illegal\n");

    return 0;
}
