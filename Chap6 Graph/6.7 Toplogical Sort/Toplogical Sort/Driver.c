#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    scanf("%d %d",&Nv,&Ne);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    Vertex * SortedVer=(Vertex *)malloc((G->Nv)*sizeof(Vertex));
    int i;
    if (TopoSort(G,SortedVer))
    {
        for (i=0;i<G->Nv;i++)
            printf("%d ",SortedVer[i]);
    }
    else
        puts("Cyclic Graph.");

    /*TopoSort(G,SortedVer);
    for (i=0;i<G->Nv;i++)
            printf("%d ",SortedVer[i]);*/

    return 0;
}
