#include "Interface.h"

extern bool * Visited;

int main(void)
{
    int Nv,Layer,K,i,j;
    Vertex V;
    scanf("%d %d",&Nv,&Layer);

    Graph G=InitGraph(Nv);
    Visited=(bool *)malloc((Nv+1)*sizeof(bool));
    for (i=0;i<Nv+1;i++)
        Visited[i]=false;

    BuildGraph(G);
    Queue Q=CreateQueue(Nv);

    scanf("%d",&K);
    for (j=0;j<K;j++)
    {
        scanf("%d",&V);
        printf("%d\n",BFS(G,V,Q,Layer));
        CleanQueue(Q);
        for (i=0;i<Nv+1;i++)
            Visited[i]=false;
    }

    return 0;
}
