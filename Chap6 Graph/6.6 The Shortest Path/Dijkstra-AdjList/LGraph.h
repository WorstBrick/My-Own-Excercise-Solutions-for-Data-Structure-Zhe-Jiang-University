#define INFINITY 65536
#define ERROR -1

typedef int Vertex;
typedef int WeightType;

//�߱�Ķ���
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Weight;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//�����
struct VerNode{
    AdjList FirstEdge;
};
typedef struct VerNode * VerList;

//ͼ
struct GNode{
    int Nv;
    int Ne;
    VerList * AllVer;
};
typedef struct GNode * Graph;
