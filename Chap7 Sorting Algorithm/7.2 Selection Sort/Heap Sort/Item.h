typedef int ElementType;


//�����ö�
typedef ElementType * CBT;
typedef int Position;
struct HNode{
    CBT StorageSpace;
    Position CurrentEle;
};
typedef struct HNode * Heap;
