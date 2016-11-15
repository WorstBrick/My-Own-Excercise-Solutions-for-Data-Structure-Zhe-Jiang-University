#include <stdbool.h>

typedef int Vertex;
typedef int WeightType;

//�߱�
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Weight;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//�����
struct VNode{
    AdjList FirstEdge;
    bool Flag;
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
    WeightType Weight;
};
typedef struct ENode * Edge;


//CBT
typedef Edge ElementType;
typedef ElementType * CBT;

//��С��
typedef int Position;
struct HNode{
    int MaxNum;
    CBT CBTree;
    Position CurrentNode;
};
typedef struct HNode * Heap;

//���鼯
typedef Vertex * UFSet;
