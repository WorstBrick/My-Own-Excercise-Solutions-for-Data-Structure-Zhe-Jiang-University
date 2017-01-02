typedef char * ElementType;
typedef enum {Empty,IsUsed,Deleted} Info;
typedef int Position;

struct KNode{
    ElementType Number;
    int CallTimes;
    Info Flag;
};
typedef struct KNode * KeysAddress;

struct HTNode{
    int TableSize;
    KeysAddress TheCells;
};
typedef struct HTNode * HashTable;
