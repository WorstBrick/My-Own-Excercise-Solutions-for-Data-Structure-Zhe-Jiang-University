typedef int ElementType;

//AVLÊ÷
typedef struct AVNode * PtrToAVNode;
struct AVNode{
    ElementType Data;
    PtrToAVNode Left;
    PtrToAVNode Right;
};
typedef PtrToAVNode AvlTree;

//CBSÊ÷
struct CNode{
    ElementType * AllNode;
};
typedef struct CNode * CBSTree;
typedef int Position;
