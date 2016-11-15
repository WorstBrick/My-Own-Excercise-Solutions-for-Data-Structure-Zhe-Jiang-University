#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    scanf("%d %d",&Nv,&Ne);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    printf("%d",Kruskal(G));

    return 0;
}
