// P3Q2.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "omp.h"
#define NTHREAD 16
static long num_steps = 1000000000;
double step;

int main()
{
    int i,j;
    double x, pi;
    double sum=0.0;
    step = 1.0 / (double)num_steps;

    for (j = 1; j <= NTHREAD; j++) {
        pi = 0;
        sum = 0.0;
        omp_set_num_threads(j);
        double start_time = omp_get_wtime();
        
        #pragma omp parallel
        {
            
            #pragma omp single
            {
                int size = omp_get_num_threads();
                printf("Num Threads = %d ", size);
            }
            #pragma omp for reduction(+:sum)
            for (i = 1; i < num_steps; i++)
            {
                x = (i + 0.5) * step;
                sum += 4.0 / (1.0 + x * x);
            }
        }
        double end_time = omp_get_wtime();

        pi = step * sum;
        printf("%f , ", pi);
        printf("Time used: %f \n", end_time - start_time);

    }
   
    return 0;

}

