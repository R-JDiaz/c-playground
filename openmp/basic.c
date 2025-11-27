#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(8);
    
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        printf("Hello from thread \n");
    }
    omp_get_thread_num();
    double end = omp_get_wtime();
    printf("Parallel time : %.4f\n\n", end - start);

    
    double start2 = omp_get_wtime();
    for (int i = 0; i < 9; i++) {
        printf("Hello from for loop \n");
    }
    double end2 = omp_get_wtime();
    printf("Loop time : %.4f", end2 - start2);
    
    
    return 0;
}