#include "Interface.h"

extern bool * VisitedDFS;
extern bool * VisitedBFS;

int main(void)
{
    int Nv,Ne;
    scanf("%d %d",&Nv,&Ne);
    VisitedBFS=(bool *)malloc(Nv*sizeof(bool));
    VisitedDFS=(bool *)malloc(Nv*sizeof(bool));
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    TravelAll_DFS(G);
    TravelAll_BFS(G);

    return 0;
}
