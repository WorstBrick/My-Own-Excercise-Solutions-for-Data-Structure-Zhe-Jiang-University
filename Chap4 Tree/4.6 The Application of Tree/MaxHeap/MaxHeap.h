#define MAXDATA 1000
#define ERROR -1
typedef int ElementType;
typedef struct HNode * Heap;
struct HNode{
    ElementType * Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
