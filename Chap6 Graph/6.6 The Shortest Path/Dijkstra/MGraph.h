typedef int Vertex;
typedef int WeightType;

//邻接矩阵
typedef WeightType * * AdjMar;

//图,Data项可选
struct GNode{
    int Nv;
    int Ne;
    AdjMar AdjRelation;
};
typedef GNode * Graph;

//边
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;


//队列
typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
