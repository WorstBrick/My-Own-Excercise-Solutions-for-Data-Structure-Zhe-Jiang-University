#include "Interface.h"
#include <stdlib.h>
#include <stdio.h>

MaxHeap CreateHeap(int MaxSize);
{
    MaxHeap H=(MaxHeap)malloc(sizeof(*H));
    H->Data=(ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;

    return H;
}

bool IsFull(MaxHeap H)
{
    return (H->Size==H->Capacity);
}

bool Insert(MaxHeap H,ElementType X)
{
    if (IsFull(H))
    {
        printf("The MaxHeap is full\n");
        return false;
    }
    int i=++H->Size;
    for (;H->Data[i/2]<X;i/=2)
        H->Data[i]=H->Data[i/2];
    H->Data[i]=X;
    return true;
}

bool IsEmpty(MaxHeap H)
{
    return (H->Size==0);
}

ElementType DeleteMax(MaxHeap H)
{
    if (IsEmpty(H))
    {
        printf("The MaxHeap is empty\n");
        return ERROR;
    }
    int Parent,Child;
    ElementType MaxItem,X;
    MaxItem=H->Data[1];
    X=H->Data[H->Size--];
    for (Parent=1;Parent*2<H->Size;Parent=Child)
    {
        Child=Parent*2;
        if ((Child!=H->Size)&&(H->Data[Child]<H->Data[Child+1]))
            Child++;
        if (X>=H->Data[Child])
            break;
        else
            H->Data[Parent]=H->Data[Child];
    }
    H->Data[Parent]=X;

    return MaxItem;
}

void PercDown(MaxHeap H,int p)
{
    int Parent,Child;
    ElementType X=H->Data[p];

    for (Parent=p;Parent*2<=H->Size;Parent=Child)
    {
        Child=Parent*2;
        if ((Child!=H->Size)&&(H->Data[Child]<H->Data[Child+1]))
            Child++;
        if (X>=H->Data[Child])
            break;
        else
            H->Data[Parent]=H->Data[Child];
    }
    H->Data[Parent]=X;
}

void BuildHeap(MaxHeap H)
{
    int i;

    for (i=H->Size/2;i>0;i--)
        PercDown(H,i);
}

void MyPercDown(MaxHeap H)//这个函数有点问题
{
    ElementType DeleteOne=H->Data[H->Size--];//拿出堆中最后一个元素
    int i=1,MaxChildIndex;

    while (i<H->Size)//这个判断条件有问题
    {
        MaxChildIndex=(H->Data[2i] > H->Data[2i+1] ? 2i:2i+1);//万一i指向的节点只有左儿子时怎么办?
        if (H->Data[MaxChildIndex]<DeleteOne)
            break;
        else
        {
            H->Data[i]=H->Data[MaxChildIndex];
            i=MaxChildIndex;
        }
    }
    H->Data[i]=DeleteOne;

}
