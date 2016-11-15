#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    Vertex S,D;
    scanf("%d %d %d %d",&Nv,&Ne,&S,&D);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    int * CountRoad=(int *)malloc(Nv*sizeof(int));
    int * RescueMen=(int *)malloc(Nv*sizeof(int));

    DijkstraModified(G,S,CountRoad,RescueMen);
    printf("%d %d",CountRoad[D],RescueMen[D]);

    return 0;
}
