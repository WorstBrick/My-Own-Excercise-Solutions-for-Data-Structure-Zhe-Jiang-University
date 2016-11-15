#define MAXNUM 100

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
typedef GNode * Graph;

//��
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;
