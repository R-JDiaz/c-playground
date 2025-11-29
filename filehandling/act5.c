#include <stdio.h>
#include <stdlib.h>

#define DAT_FILE "act.dat"
#define TMP_FILE "act.tmp"

typedef struct Student{
    int id;
    char name[100];
    char course[5];
} Student;

int main() {
    FILE *file = fopen(DAT_FILE, "rb+");
    if (!file) {
        FILE *file = fopen(DAT_FILE, "w");
        if (file) { fclose(file); };
    }

    return 0;
}