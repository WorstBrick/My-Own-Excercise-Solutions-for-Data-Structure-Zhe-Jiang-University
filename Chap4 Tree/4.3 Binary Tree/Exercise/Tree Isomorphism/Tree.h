#define NOINFO 0
#define NOTFOUND -1
typedef char ElementType;
typedef int Position;
struct TNode{
    ElementType Data;               //��������ʹ��"��̬����"����ʾ��:��ʹ��һ����������ʾ����(��������һ���ṹ����)
    Position Left;
    Position Right;
};
typedef struct TNode * BinTree;
