#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    double start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single 
        {
            printf("Synchronization tools in omp: \n");
        }
    }

    #pragma omp parallel for 
    /*  #pragma omp single 
        {
            printf("Synchronization tools in omp: ");
        } */
    for (int i = 1; i <= 10; i++) {
       
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
[1] if a forloop is inside a:

PARALLEL
-the the loop doubles(depends on the n of threads) because of multiple threads,
in each those threads the loop got called leading to multiple for loop

PARALLEL FOR 
-only one one for loop , the multiple threads are applied to each loop not on the
entire loop



*/