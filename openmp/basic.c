#include <stdio.h>
#include <omp.h>


int main() {

    int sum = 0;
    //Thread
    omp_set_num_threads(8);
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        sum += 1;
        #pragma omp single 
        {
        printf("Num of Threads: %d \n", omp_get_num_threads());
        }
    }
    printf("Sum : %d\n", sum);
    
    sum = 0;
    double end = omp_get_wtime();
    printf(" Parallel time : %.4f\n\n", end - start);
    
    //Loop
    for (int i = 0; i < 8; i++) {
        sum += 1;
    }
    double end2 = omp_get_wtime();
    printf("Loop time : %.4f", end2 - end);
    printf("Sum : %d\n", sum);
    
    return 0;
}

/* observation/s:  
    LOOP VS THREAD
    
    [A] PRINT (OUTPUT)
    LOOP WINS MODERATELY

    [B] UPDATING 
    LOOP WINS MODERATELY 


    CONCLUSION: FOR SMALLER TASKS SIMPLE FOR LOOP IS OKAY HOWEVER,
    FOR HEAVY TASKS THREADS IS RECOMMENDABLE
*/
