#include "Interface.h"

HuffmanTree Huffman(MinHeap H)
{
    int i,N;
    HuffmanTree T;
    //������С�ѵ�Ԫ������ΪHuffmanTree,������H->Size��Ȩֵ�Ѿ�������H�е�ÿ��HuffmanTree��
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
