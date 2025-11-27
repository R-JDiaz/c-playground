#include <stdio.h>
#include <omp.h>

int main() {
    
    //Thread
    omp_set_num_threads(8);
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        printf("Hello from thread \n");
        printf("Num of Threads: %d \n", omp_get_num_threads());
    }
    
    double end = omp_get_wtime();
    printf(" Parallel time : %.4f\n\n", end - start);

    
    //Loop
    double start2 = omp_get_wtime();
    for (int i = 0; i < 9; i++) {
        printf("[%d] Hello from for loop \n", i);
    }
    double end2 = omp_get_wtime();
    printf("Loop time : %.4f", end2 - start2);
    
    
    return 0;
}