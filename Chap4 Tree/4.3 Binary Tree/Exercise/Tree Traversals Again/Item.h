#define NONODE -1
//���Ķ���
typedef int ElementType;
typedef struct TNode * Position;
struct TNode{
    char flag;
    ElementType Data;
    Position Left;
    Position Right;
};
typedef Position BinTree;

//ջ�Ķ���
typedef struct SNode * Stack;
struct SNode{
    int MaxSize;
    BinTree * Data;
    int Rear;
};
