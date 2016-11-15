#include "Interface.h"

/*这道题是规定了一个进栈序列1,2,3,..,N 然后给出一个输出序列,
来判断有没有可能产生这个输出序列*/

/*我的思路:对于一个输出序列,比如3 2 1 7 5 6 4,对于其中的2来说,
则必有"此时栈顶元素为3",因为只有这样才能Pop出3这个元素*/

/*所以我的算法是:扫描输出序列,比如3 2 1 7 5 6 4,当扫到3时,
则从输入序列中读入数据,直到读到3为止,于是,1,2,3依次入栈,
这样才有可能把3这个元素弹出栈.因为栈的长度有限制,如果读到栈满
了还没读到所需元素,则这个输出序列不可能存在;如果整个输入序列
被扫完了还没找到所需元素,则这个输出序列也不可能存在*/

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
