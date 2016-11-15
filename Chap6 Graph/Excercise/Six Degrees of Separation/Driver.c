#include "Interface.h"

extern bool * Visited;

int main(void)
{
    int Nv,Ne,i;
    Vertex V;
    double ratio;

    scanf("%d %d",&Nv,&Ne);

    Queue Q=CreateQueue(Nv);
    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);
    Visited=(bool *)malloc((Nv+1)*sizeof(bool));
    for (i=0;i<Nv+1;i++)
            Visited[i]=false;

    for (V=1;V<Nv+1;V++)
    {
        ratio=(double)(InZoneVer(G,V,Q)*100/Nv);
        printf("%d: %.2f%%\n",V,ratio);
        for (i=0;i<Nv+1;i++)
            Visited[i]=false;
        CleanQueue(Q);
    }

    free(Q);
    return 0;
}
