typedef int TreeNode;

//ջ�Ķ���
typedef TreeNode ElementType;
typedef ElementType * StorageWay;
typedef int Position;
struct SNode{
    int MaxSize;
    StorageWay Data;
    Position Rear;
};
typedef struct SNode * Stack;
