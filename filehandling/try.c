#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

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
    fwrite(&student, sizeof(Student), 1, f);
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


Student customRead(FILE *f, int id) {
    rewind(f);
    Student st;
    while (fread(&st, sizeof(Student), 1, f) == 1) {
        if (st.id == id) {
            return st; // found
        }
    }
    // Return an "empty" student if not found
    Student empty = {0};
    return empty;
}


void displayStudent(FILE *f, int id) {
    Student st = customRead(f, id);
    if (st.id == 0) {
        printf("Student not found\n");
    } else {
        printf("FOUND:\n");
        printf("ID : %d\n", st.id);
        printf("NAME : %s\n", st.name);
        printf("COURSE : %s\n", st.course);
    }
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
    #pragma omp parallel
    double start = omp_get_wtime();
    {
    FILE *file = fopen(TEXT_FILE, "rb+"); 
    if (!file) {
        printf("File failed to open");
        return 1;
    }
    
    
   /*  Student student = {1, "jay entio", "BSED"};

    insert(file, student); */
    displayStudent(file, 1);
    fclose(file);    
    }
    
    double end = omp_get_wtime();
    printf("TIME: %.2f", end-start);
    return 0;
}
 