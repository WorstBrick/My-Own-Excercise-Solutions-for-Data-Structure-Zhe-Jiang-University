typedef int ElementType;
typedef struct GNode*PtrToGNode;
typedef PtrToGNode GList;
struct GNode{
    int Tag;
    union {
        ElementType Data;
        GList Sublist;
    } URegion;
    PtrToGNode Next;
};
