#include <stdbool.h>

typedef int Vertex;
typedef int WeightType;

//边表
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Cost;
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
struct GNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct GNode * Graph;

//边
struct ENode{
    int V1;
    int V2;
    WeightType Cost;
};
typedef struct ENode * Edge;

//堆
typedef Edge HeapElement;
typedef int Position;
typedef HeapElement * CBTree;
struct HNode{
    int MaxNum;
    CBTree CBT;
    Position CurrentIndex;
};
typedef struct HNode * Heap;

//并查集
typedef Vertex SetElement;
typedef SetElement * UFSet;
