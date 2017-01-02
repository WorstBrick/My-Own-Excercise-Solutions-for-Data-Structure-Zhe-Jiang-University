typedef unsigned long ElementType;

//��ϣ��ĵ�����Ԫ��
typedef struct KNode * PtrToKode;
struct KNode{
    ElementType Key;
    char * PassWord;
    PtrToKode Next;
};

//��ϣ��ӳ�䵽�ĵ�ַ
typedef PtrToKode Cells;
typedef PtrToKode Position;

//��ϣ��
struct HTNode{
    int TableSize;
    Cells AllKeys;
};
typedef struct HTNode * HashTable;
