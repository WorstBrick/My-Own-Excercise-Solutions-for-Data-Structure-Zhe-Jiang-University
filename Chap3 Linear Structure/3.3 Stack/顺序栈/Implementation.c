#define ERROR 0.0000001

//�������ľ���ʵ��
#include "Definition.h"
Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof *S);
    S->Data=(ElementType *)malloc(MaxSize);
    S->Top=-1;
    S->MaxSize=MaxSize;

    return S;
}

bool IsFull(Stack S)
{
    return (S->Top==S->MaxSize-1);
}

bool Push(Stack S,ElementType X)
{
    if (IsFull(S))
    {
        printf("The stack is fully.\n");
        return false;
    }
    S->Data[++(S->Top)]=X;
    return true;
}

bool IsEmpty(Stack S)
{
    return (S->Top==-1);
}
ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("The stack is empty.\n");
        return ERROR;  //����ERROR��ֵ���ݾ��������������,ͨ����ջԪ�ز�����ȡ����ElementType���͵�ֵ
    }
    return S->Data[(S->Top)--];
}
