typedef int Vertex;
typedef int WeightType;

//边表
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Length;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//顶点表
struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//图,顶点0~(Nhv-1)为房子,Nhv+Ngv-1为油站"计划地"
struct LGNode{
    int Nhv;//房子顶点的数量
    int Ngv;//加油站"计划地"顶点的数量
    int Ne;
    VerList AllVer;
};
typedef struct LGNode * Graph;


//堆的结点
typedef Vertex ElementType;

//堆的CBT
typedef ElementType * CBT;

//堆,以图的顶点为存储元素的最小堆,需要与dist数组进行配合使用
typedef int Position;
struct HNode{
    int MaxNum;
    CBT CBTree;
    Position CurrentNode;
};
typedef struct HNode * Heap;

//Dijkstra中的dist的改良,dist仍是一个数组,其下标对应图的顶点编号,但它的每个元素是个结构
struct DNode{
    WeightType ShortestLength;
    Position Index;//用来存放在堆中的CB树的下标
};
typedef struct DNode * PtrToDNode;

//Result是个结构数组,存放以各加油站为源点得到的结果
typedef struct{
    WeightType ShortestLength;//存放以当前下标加油站为源点得到的最短路径
    double AverageLength;
}RNode;
typedef RNode * Result;

//边,用一个三元素的数组表示;
typedef int * Edge;
