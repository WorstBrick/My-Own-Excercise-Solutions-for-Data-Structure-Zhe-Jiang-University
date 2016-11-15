#include <stdlib.h>

typedef struct PNode * PtrToPNode;
struct PNode{
    double coef;
    double expon;
    PtrToPNode next;
};
typedef PtrToPNode Polynomial;
