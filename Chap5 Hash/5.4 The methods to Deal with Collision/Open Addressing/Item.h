typedef int ElementType;
typedef int Position;

typedef enum {UnUsed,IsUsed,Deleted} StorageCondition;
struct KNode{
    ElementType Data;
    StorageCondition Flag;
};
typedef struct KNode * KeyStorage;

struct HTNode{
    int TableSize;
    KeyStorage AllKey;
};
typedef struct HTNode * HashTable;
