typedef int * Topics;

struct UNode{
    int TotalMarks;
    int FullMarkQuant;
    Topics AllTopicsMarks;
};
typedef struct UNode * UserList;

//�������õı�
typedef int * Table;

//Ͱ��Ԫ��
typedef struct EleNode * PtrToEleNode;
struct EleNode{
    int Ele;
    PtrToEleNode Next;
};
typedef PtrToEleNode EleList;

//Ͱ
struct BNode{
    EleList Head;
    EleList Tail;
};

typedef struct BNode * Bucket;
