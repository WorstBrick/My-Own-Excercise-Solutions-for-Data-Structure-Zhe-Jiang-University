#include "Interface.h"

int main(void)
{
    int Nv,Ne;
    scanf("%d %d",&Nv,&Ne);

    Graph G=InitGraph(Nv);
    BuildGraph(G,Ne);

    WeightType *Distance=(WeightType*)malloc((Nv+1)*sizeof(WeightType));
    Distance[0]=Nv;

    if (!Floyd(G))
        return 0;

    if (!EachSorceLongestPath(G,Distance))
        puts("0");
    else
    {
        Vertex SuitableSorce=FindSuitableSorce(Distance);
        printf("%d %d\n",SuitableSorce,Distance[SuitableSorce]);
    }

    return 0;
}
