#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

#define DAT_FILE "act.dat"
#define TMP_FILE "act.tmp"

typedef struct Student{
    int id;
    char name[100];
    char course[5];
} Student;

void insert(FILE *f, Student *student) {
    fseek(f, 0, SEEK_END);
    fwrite(student, sizeof(Student), 1, f);
    printf("ADDED SUCCESSFULLY\n");
}

Student get_student(FILE *f, int id) {
    rewind(f);
    Student stud;
    while(fread(&stud, sizeof(Student), 1, f) == 1) {
        if(stud.id == id) {
            return stud;
        }
    }
    Student empty = {0};  
    return empty;
}

void update(FILE *f, int id, const char *newName, const char *newCourse) {
    rewind(f);
    Student stud;
    long pos;

    while(fread(&stud, sizeof(Student), 1, f) == 1) {
        if(stud.id == id) {
            pos = ftell(f) - sizeof(Student);

            int update = 0;
            if (newName && strcmp(stud.name, newName) != 0) {
                strcpy(stud.name, newName);
                update++;
            } else if (newCourse && strcmp(stud.course, newCourse) != 0)  {
                strcpy(stud.course, newCourse);
                update++;
            }

            if (update) {
                fseek(f, pos, SEEK_SET);
                fwrite(&stud, sizeof(Student), 1, f);
                printf("Updated Succesfully\n"); 
            } else {
                printf("Nothing to Update\n");
            }
            return;
        }
    }
    printf("Student not found.\n");   
}

void displayStudent(Student student) {
    if (student.id == 0) { printf("NOT FOUND\n"); return;}
    printf("ID : %d\n", student.id);
    printf("NAME: %s\n", student.name);
    printf("COURSE: %s\n\n", student.course);
}
int main() {
    FILE *file = fopen(DAT_FILE, "rb+");
    if (!file) {
        FILE *file = fopen(DAT_FILE, "w");
        if (file) { fclose(file); };
    }

    Student stud = {2, "jay", "bscs"};
    insert(file, &stud);
    displayStudent(get_student(file, 9));
    displayStudent(get_student(file, 1));
    displayStudent(get_student(file, 2));
    update(file, 2, "RJ", "BSED");
    displayStudent(get_student(file, 2));

    
    return 0;
}