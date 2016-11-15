#include "Interface.h"

bool Floyd(Graph G,WeightType D[][MAXNUM],Vertex path[][MAXNUM])
{
    Vertex U,V,W;

    for (U=0;U<G->Nv;U++)
        for (V=0;V<G->Nv;V++)
        {
            D[U][V]=G->AdjRelation[U][V];
            path[U][V]=-1;
        }

    for (W=0;W<G->Nv;W++)
        for (U=0;U<G->Nv;U++)
            for (V=0;V<G->Nv;V++)
                if (D[U][W]+D[W][V]<D[U][V])
                {
                    D[U][V]=D[U][W]+D[W][V];
                    if (U==V && D[U][V]<0)
                        return false;
                    path[U][V]=W;
                }

    return true;
}
