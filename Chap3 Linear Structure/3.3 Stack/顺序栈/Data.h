//���ݼ��ϵľ���ʵ��
typedef double ElementType;
typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode {
    ElementType * Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;
