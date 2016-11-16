#include "Interface.h"

int main(void)
{
    int N;
    scanf("%d",&N);
    FakeTree FT=InitTree(N);

    ReadNode(FT,N);
    ListLeaves(FT,N);

    return 0;
}
