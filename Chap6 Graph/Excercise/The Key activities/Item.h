typedef int Vertex;
typedef int WeightType;

//Õº
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Time;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;
struct VNode{
    AdjList FirstEdge;
    int InDegree1;
    int InDegree2;
};
typedef struct VNode * VerList;
struct GNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct GNode * Graph;

//±ﬂ
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Time;
};
typedef struct ENode * Edge;

//∂”¡–
typedef Vertex ElementType;
typedef ElementType * StorageSpace;
typedef int Position;
struct QNode{
    int MaxNum;
    StorageSpace AllElement;
    Position Front;
    Position Rear;
};
typedef struct QNode * Queue;
