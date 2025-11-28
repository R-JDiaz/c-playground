#include <stdio.h>
#include <stdlib.h>

#define TEXT_FILE "./update.dat"

typedef struct Student {
    char id;
    char name[100];
    char course[4];
} Student;

typedef struct Header {
    int id;
    int index;
} Header;


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
    Student student = {1, "SYRENE DEJINO", "BSED"};

    insert(file, student);
    return 0; 
}