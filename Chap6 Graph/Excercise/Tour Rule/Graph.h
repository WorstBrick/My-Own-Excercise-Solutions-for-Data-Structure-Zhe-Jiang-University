typedef int Vertex;
typedef int WeightType;


//边表结点
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Length;
    WeightType Fare;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//顶点表结点
struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//图
struct LGNode{
    int Nv;
    int Ne;
    VerList Allver;
};
typedef struct LGNode * Graph;


//边
struct ENode{
    int V1;
    int V2;
    WeightType Length;
    WeightType Fare;
};
typedef struct ENode * Edge;
