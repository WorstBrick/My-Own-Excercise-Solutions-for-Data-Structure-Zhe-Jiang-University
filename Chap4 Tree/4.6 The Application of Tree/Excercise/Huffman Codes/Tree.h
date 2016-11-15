typedef char ElementType;
typedef struct TNode * PtrToTNode;
struct TNode{
    ElementType Data;
    PtrToTNode Left;
    PtrToTNode Right;
};
typedef PtrToTNode Tree;
