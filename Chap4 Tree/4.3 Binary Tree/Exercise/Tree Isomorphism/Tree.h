#define NOINFO 0
#define NOTFOUND -1
typedef char ElementType;
typedef int Position;
struct TNode{
    ElementType Data;               //在这里我使用"静态链表"来表示树:即使用一个数组来表示链表(在这里是一个结构数组)
    Position Left;
    Position Right;
};
typedef struct TNode * BinTree;
