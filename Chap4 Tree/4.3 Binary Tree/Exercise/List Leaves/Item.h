#include <stdbool.h>

typedef int Node;
struct FTNode{
    Node Left;
    Node Right;
    bool Flag;
};
typedef struct FTNode * FakeTree;

//╤сап
typedef Node ElementType;
typedef int Position;
typedef ElementType * StorageWay;
struct QNode{
    StorageWay Data;
    Position Front;
    Position Rear;
    int MaxSize;
};
typedef struct QNode * Queue;
