#include <time.h>
#include <stdio.h>
#include "1-1-1_header.h"
#define MAXK 1e7
double duration;
clock_t start,stop;

void show_time(fpt func,int n,double a[],double x)
{
    int i;

    start=clock();
    for (i=0;i<MAXK;i++)
        func(n,a,x);
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK/MAXK;
    printf("The running time is %6.2e\n",duration);
}
