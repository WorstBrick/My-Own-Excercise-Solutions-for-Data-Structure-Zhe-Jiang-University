#include "Interface.h"

HuffmanTree Huffman(MinHeap H)
{
    int i,N;
    HuffmanTree T;
    //这里最小堆的元素类型为HuffmanTree,并假设H->Size个权值已经保存在H中的每个HuffmanTree中
    BuilHeap(H);
    N=H->Size;

    for (i=1;i<N;i++)
    {
        T=(HuffmanTree)malloc(sizeof(*T));
        T->Left=DeleteMin(H);
        T->Right=DeleteMin(H);
        T->weight=T->Left->weight+T->Right->weight;
        Insert(H,T);
    }
}
