#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Position;

void Swap(ElementType Array[],int i,int j)
{
    ElementType Tmp=Array[i];
    Array[i]=Array[j];
    Array[j]=Tmp;
}

void ISortCore(ElementType A[],Position Left,Position Right)
{
    Position i,j;
    ElementType X;

    for (i=Left+1;i<=Right;i++)
    {
        X=A[i];
        for (j=i;j>Left && A[j-1]>X;j--)
            A[j]=A[j-1];
        A[j]=X;
    }
}

ElementType FindPivot(ElementType A[],Position Left,Position Right)
{
    Position Center=(Left+Right)/2;

    if (A[Left]>A[Center])
        Swap(A,Left,Center);
    if (A[Left]>A[Right])
        Swap(A,Left,Right);
    if (A[Center]>A[Right])
        Swap(A,Center,Right);

    Swap(A,Center,Right-1);

    return A[Right-1];
}

void QSortCoreRecusion(ElementType A[],Position Left,Position Right,int Cutoff)
{

    //������ϼ򵥲��Ŵ���С������ʱ,�ݹ������������if (Right-Left+1>2),�������е���������Ϊ3ʱ
    //Ϊʲô?��Ϊ����FindPivot()����Ҫ������������Ч,���Ѿ������������ź�λ��

    if (Right-Left+1>Cutoff)
    {
        ElementType Pivot=FindPivot(A,Left,Right);
        Position Low=Left,High=Right-1;
        while (true)
        {
            while (A[++Low]<Pivot);
            while (A[--High]>Pivot);

            if (Low<High)
            Swap(A,Low,High);
            else
                break;
        }
        Swap(A,Low,Right-1);
        QSortCoreRecusion(A,Left,Low-1,Cutoff);
        QSortCoreRecusion(A,Low+1,Right,Cutoff);
    }
    else
        ISortCore(A,Left,Right);
}

void QuickSort(ElementType A[],int N)
{
    int Cutoff=4;
    QSortCoreRecusion(A,0,N-1,Cutoff);
}


int main(void)
{
    ElementType Array[11]={44,12,59,36,62,43,94,7,35,52,85};
    int i;

    QuickSort(Array,11);

    for (i=0;i<11;i++)
        printf("%d ",Array[i]);

    return 0;
}
