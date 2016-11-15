#define GUARD -10001
typedef int ElementType;
typedef struct HNode * MinHeap;
struct HNode{
    ElementType * Data;
    int Size;
    int MaxSize;
};
