typedef int ElementType;

typedef struct EleNode * PtrToEleNode;
struct EleNode{
    ElementType X;
    PtrToEleNode Next;
};
typedef PtrToEleNode EleList;

//Ͱ
struct BNode{
    PtrToEleNode Head,Tail;
};
typedef struct BNode * Bucket;
