#define NONODE -1
//树的定义
typedef int ElementType;
typedef struct TNode * Position;
struct TNode{
    char flag;
    ElementType Data;
    Position Left;
    Position Right;
};
typedef Position BinTree;

//栈的定义
typedef struct SNode * Stack;
struct SNode{
    int MaxSize;
    BinTree * Data;
    int Rear;
};
