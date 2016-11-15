#define MAXSZIE 10
typedef enum{Head,Term} NodeTag;
typedef int ElementType;
struct TermNode{
    int Row,Col;
    ElementType Value;
};
typedef struct MNode * PtrToMNode;
struct MNode{
    PtrToMNode Down,Right;
    NodeTag Tag;
    union {
        PtrToMNode Next;
        struct TermNode Term;
    }URegion;
};
typedef PtrToMNode Matrix;
Matrix HeadNode[MAXSIZE];
