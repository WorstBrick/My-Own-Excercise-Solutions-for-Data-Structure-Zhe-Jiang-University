#define ERROR -1
#define INFINITY 65536

//这里图要有两种存储方式:即邻接矩阵大法和邻接表大法都要用到
typedef int Vertex;
typedef int WeightType;


//邻接矩阵表示图
typedef WeightType * * AdjMar;

struct MGNode{
    int Nv;
    int Ne;
    AdjMar AdjRelation;
};
typedef MGNode * MGraph;


//邻接表表示图
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

struct LGNode{
    int Nv;
    int Ne;
    VerList AllVers;
};
typedef struct LGNode * LGraph;


//边
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;
