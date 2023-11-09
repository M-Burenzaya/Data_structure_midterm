#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Student {
    int key;
    char student_id[12];
    struct Student* next;
} Student;

Student* hash_table[TABLE_SIZE] = {NULL};

void insert_student(char* data);
void print_table();

int main() {
    insert_student("20B1NUM0362");
    insert_student("20B1NUM1745");
    insert_student("20B1NUM2362");
    insert_student("20B1NUM5362");
    insert_student("20B1NUM2145");
    insert_student("20B1NUM0862");
    insert_student("20B1NUM3362");
    insert_student("20B1NUM9945");
    insert_student("20B1NUM4562");
    insert_student("20B1NUM3768");
    insert_student("20B1NUM2912");

    print_table();

    return 0;
}

void insert_student(char* data) {
    char first_digit = data[7];
    int index = first_digit - '0';

    Student* new_student = (Student*)malloc(sizeof(Student));

    new_student->key = index;
    strcpy(new_student->student_id, data);

    new_student->next = NULL;

    if (hash_table[index] == NULL) {
        hash_table[index] = new_student;
    } else {
        Student* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            Student* current = hash_table[i];

            printf("Slot %d:\t", i);

            while (current != NULL) {
                printf("%s\t", current->student_id);
                current = current->next;
            }

            printf("\n");
        }
    }
}
