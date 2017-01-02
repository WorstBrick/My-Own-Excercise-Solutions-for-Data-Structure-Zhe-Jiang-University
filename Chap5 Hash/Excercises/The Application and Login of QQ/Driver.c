#include "Interface.h"

int main(void)
{
    int N;
    scanf("%d",&N);

    HashTable H=InitHashTable(N);
    AppAndLog(N,H);

    return 0;
}
