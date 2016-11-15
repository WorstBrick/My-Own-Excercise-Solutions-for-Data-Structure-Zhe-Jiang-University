#define NOINFO -2
#define NOTFOUND -1
typedef char ElementType;
typedef int Position;
struct TNode{
    ElementType Data;
    Position Left;
    Position Right;
};
typedef struct TNode * BinTree;
