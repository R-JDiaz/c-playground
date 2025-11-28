#include <stdio.h>
#include <stdlib.h>

#define TEXT_FILE "./add.txt"

typedef struct Student {
    int id;
    char name[50];
    char course[5];
} Student;

int main() {
    FILE *f = fopen(TEXT_FILE, "ab+");
    if (!f) {
        printf("File failed to open");
        return 1;
    }

    Student students = {1, "RJ", "BSCS"};
    fseek(f, 0, SEEK_END);
    fwrite(&students, sizeof(Student), 1, f);
    fseek(f, 0, SEEK_SET);
    
    Student bp = {};
    fread(&bp, sizeof(Student), 1, f);

    printf("Name: %s\n", bp.name);
    fclose(f);  
    return 0;
}