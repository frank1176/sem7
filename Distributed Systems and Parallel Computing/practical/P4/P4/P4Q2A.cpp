// P4Q2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <cstdlib>
#include "omp.h"
#define NUM_THREADS 8
const long MAX = 100000;

int main()
{
    double ave = 0.0,total=0.0, *A;
    int i,nthreads;

    A = (double*)malloc(MAX * sizeof(double));
    if (A == NULL) {
        printf("Insufficient memory! Can't continue. Terminating the program abruptly.\n");
        return -1;
    }

    for (i = 0; i < MAX; i++)
    {
        A[i] = (double)i;
    }

    omp_set_num_threads(NUM_THREADS);
    double start_time = omp_get_wtime();
    #pragma omp parallel
    {
        int i, id, nthrds;
        double subtotal;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads(); 
        if (id == 0) nthreads = nthrds;

        for (i = id, subtotal = 0.0; i < MAX; i = i + nthrds) {
            subtotal += A[i];
        }
        #pragma omp critical 
        total+= subtotal;
    }

    double end_time = omp_get_wtime();
    ave =total / MAX;
    printf("%f\n", ave);
    printf("Original work took %f seconds\n", end_time - start_time);
    free(A);
    return 0;
}


