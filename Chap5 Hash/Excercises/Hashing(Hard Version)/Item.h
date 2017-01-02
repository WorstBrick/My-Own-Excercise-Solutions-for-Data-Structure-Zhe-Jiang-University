typedef int Key;
typedef int Position;

struct KNode{
    int D;
    Key Data;
    Position PrimarySite;
    Position CurrentSite;
};
typedef struct KNode * ElementType;
