#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Student {
    char key[8]; // Assuming key format like "20B1NUM"
    int student_id; // Assuming student ID is an integer
    struct Student* next; // For handling collisions
} Student;

Student* hash_table[TABLE_SIZE] = {NULL};

int hash(char* key) {
    return atoi(&key[4]) % TABLE_SIZE; // Use last 4 digits for hashing
}

void insert_student(char* data) {
    char key[8];
    strncpy(key, data, 7); // Copy the first 7 characters (e.g., "20B1NUM")

    int student_id = atoi(&data[7]); // Get the last 4 digits as student ID

    int index = hash(key);

    Student* new_student = (Student*)malloc(sizeof(Student));
    strcpy(new_student->key, key);
    new_student->student_id = student_id;
    new_student->next = NULL;

    if (hash_table[index] == NULL) {
        hash_table[index] = new_student;
    } else {
        // Handle collision by chaining
        Student* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        Student* current = hash_table[i];
        while (current != NULL) {
            printf("%s%d -> ", current->key, current->student_id);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    char data1[] = "20B1NUM0362";
    char data2[] = "20B1NUM1745";
    char data3[] = "20C4NUM234";

    insert_student(data1);
    insert_student(data2);
    insert_student(data3);

    print_table();

    return 0;
}
