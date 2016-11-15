#include "Interface.h"
extern bool * Visited;

int main(void)
{
    int N,D,i;
    scanf("%d %d",&N,&D);
    N+=2;
    Graph G=InitGraph(N);
    BuildGraph(G,D);
    Visited=(bool *)malloc((N)*sizeof(bool));
    for (i=0;i<N;i++)
        Visited[i]=false;

    if (BFS(G))
        printf("Yes\n");
    else
        puts("No");

    return 0;
}
