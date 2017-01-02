typedef int ElementType;
typedef int Position;

typedef struct KNode * PtrToKNode;
struct KNode{
    ElementType Data;
    PtrToKNode Next;
};
typedef PtrToKNode KeyList;

struct ANode{
    KeyList SynKeyHead;
};
typedef struct ANode * AddressSpace;

struct HTNode{
    int TableSize;
    AddressSpace AllKey;
};
typedef struct HTNode * HashTable;
