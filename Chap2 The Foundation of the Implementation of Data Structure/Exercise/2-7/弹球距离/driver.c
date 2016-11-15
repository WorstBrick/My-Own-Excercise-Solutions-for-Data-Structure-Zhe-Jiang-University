#include <stdio.h>
#define TOL 1E-2

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
double dist( double h, double p )
{
    double temp=p*h;
    int n,i;

    for (n=0;temp>=TOL;n++)
        temp*=p;
    for (i=0,temp=1;i<n+1;i++)
        temp*=p;
    return 2*h*(1-temp)/(1-p)-h;
}
