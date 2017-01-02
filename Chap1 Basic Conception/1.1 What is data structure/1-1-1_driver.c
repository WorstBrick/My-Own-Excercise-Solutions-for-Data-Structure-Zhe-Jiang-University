#include "1-1-1_header.h"
#define MAXN 10
#include <stdlib.h>
double f1(int n,double a[],double x);
double f2(int n,double a[],double x);
double a[MAXN];
int main(int argc,char *argv[])
{
    double x=atof(argv[1]);
    int i;

    for (i=0;i<MAXN;i++)
        a[i]=i;

    show_time(f1,MAXN,a,x);
    show_time(f2,MAXN,a,x);

    return 0;
}
