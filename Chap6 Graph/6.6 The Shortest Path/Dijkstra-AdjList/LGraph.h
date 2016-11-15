#define INFINITY 65536
#define ERROR -1

typedef int Vertex;
typedef int WeightType;

//边表的顶点
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Weight;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//顶点表
struct VerNode{
    AdjList FirstEdge;
};
typedef struct VerNode * VerList;

//图
struct GNode{
    int Nv;
    int Ne;
    VerList * AllVer;
};
typedef struct GNode * Graph;
