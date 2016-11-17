//�߱�
typedef int Vertex;
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

//ͼ
struct GNode{
    int Nv;
    int Ne;
    VerList AllVers;
};
typedef struct GNode * Graph;

//�ߵĶ���
struct ENode{
    Vertex V1;
    Vertex V2;
};
typedef struct ENode * Edge;



//���еĶ���
typedef Vertex ElementType;
typedef int Position;
typedef ElementType * StorageWay;
struct QNode{
    StorageWay Data;
    Position Front,Rear;
    int MaxSize;
};
typedef struct QNode * Queue;
