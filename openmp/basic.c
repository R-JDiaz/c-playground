#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        printf("Hello from thread \n");
    }
    omp_get_thread_num();
    printf("ues");
    return 0;
}