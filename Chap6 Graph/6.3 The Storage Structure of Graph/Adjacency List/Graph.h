#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

//边的定义,与邻接矩阵里边的定义一样
typedef struct ENode * PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

//邻接点的定义
typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

typedef struct GNode * PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;
