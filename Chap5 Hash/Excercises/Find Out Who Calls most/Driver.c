#include "Interface.h"

int main(void)
{
    int N;
    scanf("%d",&N);

    HashTable H=InitHashTable(2*N*10/7);
    BuildHashTable(N,H);
    ShowMax(H);

    return 0;
}
