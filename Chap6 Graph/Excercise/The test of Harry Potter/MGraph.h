#define INFINITY 65536

typedef int Vertex;
typedef int WeightType;

//ͼ
struct GNode{
    int Nv;
    int Ne;
    WeightType * * AdjM;
};
typedef struct GNode * Graph;

//��
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;
