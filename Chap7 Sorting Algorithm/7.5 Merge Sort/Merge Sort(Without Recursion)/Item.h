typedef int ElementType;
typedef int Position;

//ջ��Ԫ��:ָ��һ���ṹ��ָ��
struct EndNode{
    Position Left;
    Position Right;
};
typedef struct EndNode * SElement;

//ջ
typedef SElement * StorageMode;
struct SNode{
    int MaxNum;
    StorageMode StorageSpace;
    Position LatestEle;
};
typedef struct SNode * Stack;
