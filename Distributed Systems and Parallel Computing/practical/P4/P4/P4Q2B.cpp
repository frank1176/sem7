// P4Q2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <cstdlib>
#include "omp.h"
#define NUM_THREADS 8
const long MAX = 100000;

int main()
{
    double ave = 0.0, * A;
    int i, nthreads;

    A = (double*)malloc(MAX * sizeof(double));
    if (A == NULL) {
        printf("Insufficient memory! Can't continue. Terminating the program abruptly.\n");
        return -1;
    }

    for (i = 0; i < MAX; i++)
    {
        A[i] = (double)i;
    }
    int id, nthrds;
    //double ave;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if (id == 0) nthreads = nthrds;

    omp_set_num_threads(NUM_THREADS);
    double start_time = omp_get_wtime();
    
    #pragma omp parallel for reduction(+:ave)
    for (i = id; i < MAX; i = i + nthrds) {
            ave += A[i];
    }
    
    double end_time = omp_get_wtime();
    ave = ave / MAX;
    printf("%f\n", ave);
    printf("Original work took %f seconds\n", end_time - start_time);
    free(A);
    return 0;
}


