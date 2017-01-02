typedef int ElementType;
typedef enum {Empty,IsUsed,Deleted} Info;
typedef int Position;

//¹þÏ£±íÔªËØ
struct KNode{
    ElementType Data;
    Info Flag;
};
typedef struct KNode * StorageSpace;

struct HTNode{
    int TableSize;
    StorageSpace Cells;
};
typedef struct HTNode * HashTable;
