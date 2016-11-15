#include <stdbool.h>

typedef int Vertex;
typedef int WeightType;

//�߱�
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    WeightType Cost;
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
struct GNode{
    int Nv;
    int Ne;
    VerList AllVer;
};
typedef struct GNode * Graph;

//��
struct ENode{
    int V1;
    int V2;
    WeightType Cost;
};
typedef struct ENode * Edge;

//��
typedef Edge HeapElement;
typedef int Position;
typedef HeapElement * CBTree;
struct HNode{
    int MaxNum;
    CBTree CBT;
    Position CurrentIndex;
};
typedef struct HNode * Heap;

//���鼯
typedef Vertex SetElement;
typedef SetElement * UFSet;
