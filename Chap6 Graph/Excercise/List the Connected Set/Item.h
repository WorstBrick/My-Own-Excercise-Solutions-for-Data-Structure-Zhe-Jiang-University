//边表
typedef int Vertex;
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

//图
struct GNode{
    int Nv;
    int Ne;
    VerList AllVers;
};
typedef struct GNode * Graph;

//边的定义
struct ENode{
    Vertex V1;
    Vertex V2;
};
typedef struct ENode * Edge;



//队列的定义
typedef Vertex ElementType;
typedef int Position;
typedef ElementType * StorageWay;
struct QNode{
    StorageWay Data;
    Position Front,Rear;
    int MaxSize;
};
typedef struct QNode * Queue;
