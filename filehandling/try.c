#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEXT_FILE "./update.dat"
#define stSize sizeof(Student)

typedef struct Student {
    int id;
    char name[100];
    char course[5]; 
} Student;

typedef enum {
    id,
    name,
    course
} StudentAttr;

void insert(FILE *f, Student student) {
    fseek(f, 0, SEEK_END);
    fwrite(&student, stSize, 1, f);
}

size_t solveAttributeDistance(StudentAttr att) {
    if (att == id) {
        return sizeof(int);
    } else if (att == name) {
        return 100;
    } else if (att == course) {
        return 5;
    } else {
        printf("Not an attribute of Student\n");
        return 0;
    }
}


Student customRead(FILE *f, StudentAttr att, int id) {
    rewind(f);
    bool found;
    int index_counter = 0;
    int buffer = malloc(4);
    Student st;
    while (found = false) {
        fseek(f, index_counter, SEEK_SET);
        if (fread(&buffer, sizeof(int), 1, f) == id) {
            fread(&st, sizeof(Student), 1, f);
            found = true;
        } 
        found = false;
    }
    return st;
}
void displayStudent(FILE *f, StudentAttr att, int id) {
    Student st = customRead(f, att, id);
    printf("FOUND: ");
    printf("ID : %d", st.id);
    printf("NAME : %s", st.name);
    printf("COURSE : %s", st.course);
}
void read(FILE *f) {
    Student sModel;
    rewind(f); 

    if (fread(&sModel, stSize, 1, f) == 1) {
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
