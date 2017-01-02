typedef int * Topics;

struct UNode{
    int TotalMarks;
    int FullMarkQuant;
    Topics AllTopicsMarks;
};
typedef struct UNode * UserList;

//表排序用的表
typedef int * Table;

//桶链元素
typedef struct EleNode * PtrToEleNode;
struct EleNode{
    int Ele;
    PtrToEleNode Next;
};
typedef PtrToEleNode EleList;

//桶
struct BNode{
    EleList Head;
    EleList Tail;
};

typedef struct BNode * Bucket;
