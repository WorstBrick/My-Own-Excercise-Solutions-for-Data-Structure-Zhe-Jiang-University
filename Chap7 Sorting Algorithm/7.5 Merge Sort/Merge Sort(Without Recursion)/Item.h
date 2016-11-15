typedef int ElementType;
typedef int Position;

//栈的元素:指向一个结构的指针
struct EndNode{
    Position Left;
    Position Right;
};
typedef struct EndNode * SElement;

//栈
typedef SElement * StorageMode;
struct SNode{
    int MaxNum;
    StorageMode StorageSpace;
    Position LatestEle;
};
typedef struct SNode * Stack;
