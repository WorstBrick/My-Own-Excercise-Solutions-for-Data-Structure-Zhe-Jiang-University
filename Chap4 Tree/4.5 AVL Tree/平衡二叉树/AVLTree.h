typedef int ElementType;
typedef struct AVLNode * Position;
typedef Position AVLTree;
typedef struct AVLNode{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
