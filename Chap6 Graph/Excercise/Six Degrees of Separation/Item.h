typedef int Vertex;

//边表
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//顶点表
struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//边
struct ENode{
    Vertex V1;
    Vertex V2;
};
typedef struct ENode * Edge;

//图
struct GNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct GNode * Graph;


//队列
typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
