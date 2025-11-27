#include <stdio.h>
#include <omp.h>
#include <windows.h>

int main() {

    int n = 20;
    omp_set_num_threads(8);

    double start = omp_get_wtime();

    printf("Using schedule: \n");
    #pragma omp parallel 
    {
        #pragma omp single
        {
            printf("Runtime Chosen Schedule:\n");
        }
    }

    #pragma omp parallel for schedule(runtime)
        for (int i = 0; i < n; i++ ) {
            if (i % 2 == 0) {
                Sleep(20);
            } else {
                Sleep(100);
            }

            printf("Thread %d - iteration %d\n", omp_get_thread_num(), i);
        }
    double end = omp_get_wtime();
    printf("\nTotal Elapsed Time : %.3f seconds \n", end - start);

    return 0;
}