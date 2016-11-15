#include <stdbool.h>

typedef int Vertex;
typedef int WeightType;

//边表
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Weight;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//顶点表
struct VNode{
    AdjList FirstEdge;
    bool Flag;
};
typedef struct VNode * VerList;

//图
struct LGNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct LGNode * Graph;

//边
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;


//CBT
typedef Edge ElementType;
typedef ElementType * CBT;

//最小堆
typedef int Position;
struct HNode{
    int MaxNum;
    CBT CBTree;
    Position CurrentNode;
};
typedef struct HNode * Heap;

//并查集
typedef Vertex * UFSet;
