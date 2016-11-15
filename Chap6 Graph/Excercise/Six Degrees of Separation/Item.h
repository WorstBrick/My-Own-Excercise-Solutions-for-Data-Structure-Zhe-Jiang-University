typedef int Vertex;

//�߱�
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//�����
struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//��
struct ENode{
    Vertex V1;
    Vertex V2;
};
typedef struct ENode * Edge;

//ͼ
struct GNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct GNode * Graph;


//����
typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
