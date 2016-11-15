typedef int ElementType;
typedef struct TNode * SonNode;
struct TNode{
    ElementType Data;
    SonNode Left;
    SonNode Right;
};
typedef SonNode BSTree;
