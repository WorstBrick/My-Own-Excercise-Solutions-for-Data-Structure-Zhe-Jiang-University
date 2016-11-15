#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    Vertex S,D;
    scanf("%d %d %d %d",&Nv,&Ne,&S,&D);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    WeightType * dist;
    Vertex * path=(Vertex *)malloc(Nv*sizeof(Vertex));
    dist=Dijkstra(G,S,path);
    printf("%d %d",dist[D],FindTotalFare(G,D,path));

    return 0;
}
