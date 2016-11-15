typedef struct PNode * PtrToPNode;
struct PNode{
    int coe;
    int expon;
    PtrToPNode next;
};
typedef PtrToPNode Poly;
typedef struct{
    int quant;
    int * poly;
} MulPoly;

