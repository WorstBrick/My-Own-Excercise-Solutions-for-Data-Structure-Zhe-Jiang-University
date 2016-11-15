typedef struct PNode * Item;
struct PNode{
    int Coe;
    int Expo;
    Item Next;
};

struct HeadNode{
    Item FirstItem;
};
typedef struct HeadNode * Poly;
