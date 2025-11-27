#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    #pragma omp parallel for 
    for (int i = 1; i <= 10; i++) {
        #pragma omp critical 
        {
            sum += 1;
            printf("Thread %d added %d, sum = %d\n", omp_get_thread_num(), i, sum);
        }
    }

    printf("Total sum = %d\n", sum);
    return 0;
}