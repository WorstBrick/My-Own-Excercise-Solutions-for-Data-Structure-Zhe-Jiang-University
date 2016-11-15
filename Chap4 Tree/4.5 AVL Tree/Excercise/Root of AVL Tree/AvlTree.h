typedef int ElementType;
typedef struct AVNode * SonNode;
struct AVNode{
    ElementType Data;
    SonNode Left;
    SonNode Right;
};
typedef SonNode ATree;
//这个AVL树没有Height或者BF字段
