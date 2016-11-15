#include "Interface.h"

extern bool * Visited;

int main(void)
{
    int N,E,i;
    Graph G;
    scanf("%d %d",&N,&E);
    Visited=(bool *)malloc(N*sizeof(bool));

    for (i=0;i<N;i++)
        Visited[i]=false;
    G=InitGraph(N);
    if (!BuildGraph(G,E))
    {
       int j;
       for (j=0;j<2;j++)
       {
            for (i=0;i<N;i++)
            {
                printf("{");
                Visit(i);
                printf(" }\n");
            }
       }
       return 0;
    }

    TravelAll_DFS(G);

    for (i=0;i<N;i++)
        Visited[i]=false;
    TravelAll_BFS(G);
    free(Visited);

    return 0;
}
