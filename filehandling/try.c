#include <stdio.h>
#include <stdlib.h>

#define TEXT_FILE "./update.dat"

typedef struct Student {
    int id;
    char name[100];
    char course[5];   // B S E D \0 = 5 bytes
} Student;

void insert(FILE *f, Student student) {
    fseek(f, 0, SEEK_END);
    fwrite(&student, sizeof(Student), 1, f);
}

void read(FILE *f) {
    Student sModel;
    rewind(f); 

    if (fread(&sModel, sizeof(Student), 1, f) == 1) {
        printf("ID: %d\n", sModel.id);
        printf("Name: %s\n", sModel.name);
        printf("Course: %s\n", sModel.course);
    } else {
        printf("Nothing to read\n");
    }
}

int main() {
    FILE *file = fopen(TEXT_FILE, "wb+"); 
    if (!file) {
        printf("File failed to open");
        return 1;
    }

    Student student = {1, "RJ DIAZ", "BSED"};

    insert(file, student);
    read(file);

    fclose(file);
    return 0;
}
