// P3Q2.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "omp.h"
#define NTHREAD 16
static long num_steps = 100000000;
double step;

int main()
{
    int j;
    double x, pi;
    double sum[NTHREAD];
    step = 1.0 / (double)num_steps;

    omp_set_num_threads(NTHREAD);
    double start_time = omp_get_wtime();
    #pragma omp parallel
    {
        int i=0;
        int size = omp_get_num_threads();
        int rank = omp_get_thread_num();
        for (i = 0,sum[rank]=0.0; i < num_steps; i=i+size)
        {
            x = (i + 0.5) * step;
            sum[rank] += 4.0 / (1.0 + x * x);
        }
        printf("ID(%d) sum = %f\n",rank,sum[rank]);
    }
    double end_time = omp_get_wtime();

    for (j= 0,pi =0; j < NTHREAD; j++) {
        pi += step * sum[j];
    }
    
    printf("%f\n", pi);
    printf("Time used: %f",end_time-start_time);
    return 0;
    
}

