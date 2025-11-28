#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define TEXT_FILE "./openmp-files.txt"

typedef struct Profile {
    long int id;
    char name[100];
    char course[100];
} Profile;

omp_lock_t file_lock;

void process() {
    int id = omp_get_thread_num();
    omp_set_lock(&file_lock);

    FILE *f = fopen(TEXT_FILE, "rb+");
    if (!f) {
        printf("Thread %d: Failed to open file\n", id);
        omp_unset_lock(&file_lock);
        return;
    }

    char buff[100];
    memset(buff, 0, sizeof(buff));
    fread(buff, sizeof(char), 100, f);
    long int val = atol(buff);

    printf("Thread #%d : %ld -> %ld\n", id, val, val + 1);

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%ld", val + 1);

    fclose(f);
    omp_unset_lock(&file_lock);
}

int main() {
    FILE *f = fopen(TEXT_FILE, "w");
    fprintf(f, "0");
    fclose(f);

    omp_init_lock(&file_lock);

    #pragma omp parallel for
    for (int i = 0; i < 5; i++) {
        process();
    }
    omp_destroy_lock(&file_lock);

    return 0;
}
