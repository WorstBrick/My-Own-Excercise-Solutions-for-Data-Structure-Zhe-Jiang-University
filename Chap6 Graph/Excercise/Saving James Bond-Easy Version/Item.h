typedef int Vertex;

//邻接点,即边表元素的定义
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//读入的坐标
struct CoorNode{
    double X;
    double Y;
};
typedef struct CoorNode * Coordinate;


//顶点表
struct VNode{
    union Point{
        Coordinate P;
        int Flag;
};
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//图
struct LGraph{
    int Nv;
    int PresentV;
    VerList AllVer;
};
typedef struct LGraph * Graph;


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
