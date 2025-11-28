#include <stdio.h>
#include <stdlib.h>

#define TEXT_FILE "./update.txt"

typedef struct Student {
    int id;
    char name[100];
    char course[4];
} Student;

void insert(FILE *f, Student student) {
    fseek(f, 0, SEEK_END);
    fwrite(&student, sizeof(Student), 1, f);
}

int main() {
    FILE *file = fopen(TEXT_FILE, "ab+");
    if (!file) {
        printf("File failed to open");
        return 1;
    }
    Student student = {1, "RJ DIAZ", "BSCS"};

    insert(file, student);
    return 0; 
}