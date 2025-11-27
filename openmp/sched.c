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

    omp_set_schedule(omp_sched_static, 5);
  /*   omp_set_schedule(omp_sched_dynamic, 2); */
    /* omp_set_schedule(omp_sched_guided, 4); */

    #pragma omp parallel for schedule(runtime)
        for (int i = 0; i < n; i++ ) {
            /* if (i % 2 == 0) {
                Sleep(20);
            } else {
                Sleep(100);
            } */

            printf("Thread %d - iteration %d\n", omp_get_thread_num(), i);
        }
    double end = omp_get_wtime();
    printf("\nTotal Elapsed Time : %.3f seconds \n", end - start);

    return 0;
}

/* 
notes:

static - assigns a specific(evenly) iteration in each thread before execution(loop)
dynamic - can be used as a loadbalancer, gives more on fast threads
auto - lets the compiler choose what's best sched type to run
guided - loads in large chunk sizes and decreases exponentially
runtime - the sched type are assigned depending on the inputs(code)

*/