typedef int Vertex;

//�ڽӵ�,���߱�Ԫ�صĶ���
typedef struct AdjNode * PtrToAdjNode;
struct AdjNode{
    Vertex V;
    PtrToAdjNode Next;
};
typedef PtrToAdjNode AdjList;

//���������
struct CoorNode{
    double X;
    double Y;
};
typedef struct CoorNode * Coordinate;


//�����
struct VNode{
    union Point{
        Coordinate P;
        int Flag;
};
    AdjList FirstEdge;
};
typedef struct VNode * VerList;

//ͼ
struct LGraph{
    int Nv;
    int PresentV;
    VerList AllVer;
};
typedef struct LGraph * Graph;


//����
typedef Vertex ElementType;
typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
