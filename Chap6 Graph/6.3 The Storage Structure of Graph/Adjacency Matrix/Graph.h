#define INFINITY 65536
#define ERROR -1

typedef int Vertex;
typedef int WeightType;

//�ڽӾ���
typedef WeightType * * AdjMar;

//ͼ,Data���ѡ
struct GNode{
    int Nv;
    int Ne;
    AdjMar AdjRelation;
};
typedef GNode * MGraph;

//��
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;


//BFS��Ҫ�õ��Ķ���
typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;