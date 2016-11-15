#define ERROR -1
#define INFINITY 65536

//����ͼҪ�����ִ洢��ʽ:���ڽӾ���󷨺��ڽӱ�󷨶�Ҫ�õ�
typedef int Vertex;
typedef int WeightType;


//�ڽӾ����ʾͼ
typedef WeightType * * AdjMar;

struct MGNode{
    int Nv;
    int Ne;
    AdjMar AdjRelation;
};
typedef MGNode * MGraph;


//�ڽӱ��ʾͼ
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

struct VNode{
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

struct LGNode{
    int Nv;
    int Ne;
    VerList AllVers;
};
typedef struct LGNode * LGraph;


//��
struct ENode{
    Vertex V1;
    Vertex V2;
    WeightType Weight;
};
typedef struct ENode * Edge;
