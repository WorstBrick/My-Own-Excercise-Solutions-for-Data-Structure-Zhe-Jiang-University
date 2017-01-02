typedef unsigned long ElementType;

//哈希表的单链表元素
typedef struct KNode * PtrToKode;
struct KNode{
    ElementType Key;
    char * PassWord;
    PtrToKode Next;
};

//哈希表被映射到的地址
typedef PtrToKode Cells;
typedef PtrToKode Position;

//哈希表
struct HTNode{
    int TableSize;
    Cells AllKeys;
};
typedef struct HTNode * HashTable;
