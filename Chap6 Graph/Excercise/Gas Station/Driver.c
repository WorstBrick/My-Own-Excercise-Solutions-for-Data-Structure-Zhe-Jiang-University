#include "Interface.h"

int main(void)
{
    int Nhv,Ngv,K,Distance,Index;
    scanf("%d %d %d %d",&Nhv,&Ngv,&K,&Distance);

    Graph G=InitGraph(Nhv,Ngv);
    BuildGraph(G,K);

    Result Output=(Result)malloc(Ngv*sizeof(RNode));
    for (Index=0;Index<Ngv;Index++)
    {
        Output[Index].AverageLength=0.0;
        Output[Index].ShortestLength=INFINITY;
    }

    for (Index=0;Index<Ngv;Index++)
        DijkstraModified(G,Nhv+Index,Output,Index);

    if (Solution(Output,Distance,Ngv))
        puts("No Solution");

    return 0;
}
