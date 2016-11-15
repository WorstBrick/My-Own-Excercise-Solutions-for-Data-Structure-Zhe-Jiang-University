typedef int ElementType;
typedef struct TNode* Position;
struct TNode{
    ElementType Data;
    Position Left;
    Position Right;
};
typedef Position BinTree;
