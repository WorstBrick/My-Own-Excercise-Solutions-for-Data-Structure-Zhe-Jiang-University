typedef int ElementType;
typedef struct AVNode * SonNode;
struct AVNode{
    ElementType Data;
    SonNode Left;
    SonNode Right;
};
typedef SonNode ATree;
//���AVL��û��Height����BF�ֶ�
