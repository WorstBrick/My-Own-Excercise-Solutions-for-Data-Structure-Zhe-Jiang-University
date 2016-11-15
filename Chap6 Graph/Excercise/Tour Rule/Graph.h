typedef int Vertex;
typedef int WeightType;


//�߱���
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Length;
    WeightType Fare;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//�������
struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//ͼ
struct LGNode{
    int Nv;
    int Ne;
    VerList Allver;
};
typedef struct LGNode * Graph;


//��
struct ENode{
    int V1;
    int V2;
    WeightType Length;
    WeightType Fare;
};
typedef struct ENode * Edge;
