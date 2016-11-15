typedef int ElementType;
typedef int Position;
struct SNode{
    int MaxSize;
    ElementType * Data;
    Position Top;
};
typedef struct SNode * Stack;
