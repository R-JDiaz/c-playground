#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    double start = omp_get_wtime();
    #pragma omp parallel for 
    for (int i = 1; i <= 10; i++) {
       /*  #pragma omp single 
        {
            printf("Synchronization tools in omp: ");
        } */
        #pragma omp critical 
        {
            sum += 1;
            printf("Thread %d added %d, sum = %d\n", omp_get_thread_num(), i, sum+1);
        }
    }
    double end = omp_get_wtime();
    printf("Time: %.3f ", end -start);
    printf("Total sum = %d\n", sum);
    return 0;
}

/* notes:
critical - (mutual exclusion) ensures that the block of code run only in a single thread.


observations:
-if a for loop pragram omp para

*/