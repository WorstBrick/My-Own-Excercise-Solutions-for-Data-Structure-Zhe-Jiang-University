typedef int Vertex;
typedef int WeightType;

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
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//ͼ,����0~(Nhv-1)Ϊ����,Nhv+Ngv-1Ϊ��վ"�ƻ���"
struct LGNode{
    int Nhv;//���Ӷ��������
    int Ngv;//����վ"�ƻ���"���������
    int Ne;
    VerList AllVer;
};
typedef struct LGNode * Graph;


//�ѵĽ��
typedef Vertex ElementType;

//�ѵ�CBT
typedef ElementType * CBT;

//��,��ͼ�Ķ���Ϊ�洢Ԫ�ص���С��,��Ҫ��dist����������ʹ��
typedef int Position;
struct HNode{
    int MaxNum;
    CBT CBTree;
    Position CurrentNode;
};
typedef struct HNode * Heap;

//Dijkstra�е�dist�ĸ���,dist����һ������,���±��Ӧͼ�Ķ�����,������ÿ��Ԫ���Ǹ��ṹ
struct DNode{
    WeightType ShortestLength;
    Position Index;//��������ڶ��е�CB�����±�
};
typedef struct DNode * PtrToDNode;

//Result�Ǹ��ṹ����,����Ը�����վΪԴ��õ��Ľ��
typedef struct{
    WeightType ShortestLength;//����Ե�ǰ�±����վΪԴ��õ������·��
    double AverageLength;
}RNode;
typedef RNode * Result;

//��,��һ����Ԫ�ص������ʾ;
typedef int * Edge;
