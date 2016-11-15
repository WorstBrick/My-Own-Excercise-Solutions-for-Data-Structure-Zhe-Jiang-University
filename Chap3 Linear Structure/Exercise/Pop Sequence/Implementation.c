#include "Interface.h"

/*������ǹ涨��һ����ջ����1,2,3,..,N Ȼ�����һ���������,
���ж���û�п��ܲ�������������*/

/*�ҵ�˼·:����һ���������,����3 2 1 7 5 6 4,�������е�2��˵,
�����"��ʱջ��Ԫ��Ϊ3",��Ϊֻ����������Pop��3���Ԫ��*/

/*�����ҵ��㷨��:ɨ���������,����3 2 1 7 5 6 4,��ɨ��3ʱ,
������������ж�������,ֱ������3Ϊֹ,����,1,2,3������ջ,
�������п��ܰ�3���Ԫ�ص���ջ.��Ϊջ�ĳ���������,�������ջ��
�˻�û��������Ԫ��,�����������в����ܴ���;���������������
��ɨ���˻�û�ҵ�����Ԫ��,������������Ҳ�����ܴ���*/

Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof(*S));
    S->MaxSize=MaxSize;
    S->Data=(ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
    S->Top=0;
    S->Data[0]=0;

    return S;
}

bool IsFull(Stack S)
{
    return (S->Top==S->MaxSize);
}

bool Push(Stack S,ElementType X)
{
    if (IsFull(S))
        return false;
    S->Data[++S->Top]=X;
    return true;
}

bool IsEmpty(Stack S)
{
    return (S->Top==0);
}


ElementType Pop(Stack S)
{
    if (IsEmpty(S))
        return ERROR;

    ElementType X=S->Data[S->Top--];
    return X;
}


void CleanStack(Stack S)
{
    S->Top=0;
}


bool IsPopSequence(int N,Stack S)
{
    ElementType PopElement,PushElement;
    int i;

    for (i=0,PushElement=1;i<N;i++)
    {
        scanf("%d",&PopElement);
        if (S->Data[S->Top]!=PopElement)
        {
            while (PushElement!=PopElement)
            {
                Push(S,PushElement);
                PushElement++;
                if (PushElement>N)
                    return false;
            }
            if (!Push(S,PushElement))
                return false;
            PushElement++;
        }
        //PushElement++;
        Pop(S);
    }

    return true;
}
