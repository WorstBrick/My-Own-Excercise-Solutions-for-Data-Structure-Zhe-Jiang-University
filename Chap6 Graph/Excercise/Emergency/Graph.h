typedef int Vertex;
typedef int WeightType;
typedef int DataType;

//�߱�
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Length;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//�����
struct VNode{
    DataType MensNumber;
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//ͼ
struct LGNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct LGNode * Graph;

//��
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Length;
};
typedef struct ENode * Edge;
