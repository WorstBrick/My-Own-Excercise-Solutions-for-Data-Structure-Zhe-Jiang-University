typedef int Vertex;
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;
typedef PtrToAdjNode * Node;

typedef struct GNode * Graph;
struct GNode{
    int Nv;
    int Ne;
    Node AllNodes;
};
//边的定义
struct ENode{
    Vertex V1;
    Vertex V2;
};
typedef struct ENode * Edge;



//队列的定义
typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
