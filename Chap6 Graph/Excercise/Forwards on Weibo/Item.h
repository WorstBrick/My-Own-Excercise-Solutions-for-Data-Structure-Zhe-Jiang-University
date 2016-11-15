typedef int Vertex;

typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

struct VNode {
    AdjList FirstEdge;
};
typedef struct VNode * NodeList;

struct GNode{
    int Nv;
    int Ne;
    NodeList AllNode;
};
typedef struct GNode * Graph;


typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
