typedef int Vertex;
typedef int WeightType;

//ͼ
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Time;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;
struct VNode{
    AdjList FirstEdge;
    int InDegree;
};
typedef struct VNode * VerList;
struct GNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct GNode * Graph;

//ͼ�ı�
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Time;
};
typedef struct ENode * Edge;


//����
typedef Vertex ElementType;
typedef int Position;
typedef ElementType * StorageForm;
struct QNode{
    int MaxNum;
    StorageForm StorageSpace;
    Position Front;
    Position Rear;
};
typedef struct QNode * Queue;
