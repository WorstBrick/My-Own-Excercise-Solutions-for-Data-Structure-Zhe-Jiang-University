typedef struct PolyNode * PtrToPolyNode;
typedef struct PolyNode{
    int Coef;
    int Expon;
    PtrToPolyNode Next;
};
typedef PtrToPolyNode Polynomial;
