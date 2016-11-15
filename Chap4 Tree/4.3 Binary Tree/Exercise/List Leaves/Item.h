#include <stdbool.h>
#define NOSON -1
#define ERROR -2

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
