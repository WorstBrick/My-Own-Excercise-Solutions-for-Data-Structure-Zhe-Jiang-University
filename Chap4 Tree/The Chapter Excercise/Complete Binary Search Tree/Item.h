typedef int ElementType;

//AVL��
typedef struct AVNode * PtrToAVNode;
struct AVNode{
    ElementType Data;
    PtrToAVNode Left;
    PtrToAVNode Right;
};
typedef PtrToAVNode AvlTree;

//CBS��
struct CNode{
    ElementType * AllNode;
};
typedef struct CNode * CBSTree;
typedef int Position;
