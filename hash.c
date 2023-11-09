#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10           //0-9 10 цифрт харгалзуулан

typedef struct Student {
    int value;                  //Hash хүснэгтийн index
    char student_id[12];        //Oюутны ID
    struct Student* next;       //Дараагын элементын заагч
} Student;

Student* hash_table[TABLE_SIZE] = {NULL};       //Hash хүснэгт

void insert_student(char* data);
void print_table();

int main() {                        //туршиж үзэхэд хэрэглэсэн өгөгдөл
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
    char first_digit = data[7];         //эхний оронг авна
    int index = first_digit - '0';      //'0' Ascii value 48 тул хассанаар бүхэл тоон утгыш авна

    Student* new_student = (Student*)malloc(sizeof(Student));

    new_student->value = index;         //hash value г хийнэ
    strcpy(new_student->student_id, data);  //Оюутны ID - г хийнэ

    if (hash_table[index] == NULL) {    //Хүснэгт хоосон бол
        hash_table[index] = new_student;//оруулсан оюутны ID нь эхний элемент
    } else {                            //хоосон биш бол элементийг сүүлд нь хийнэ
        Student* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
    new_student->next = NULL;
}

void print_table() {                    //Hash бүтцийн элемнтүүдийг хэвэлнэ
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {    //Bucket Хоосон биш үед
            Student* current = hash_table[i];

            printf("Slot %d:\t", i);

            while (current != NULL) {   //Bucket доторх элемент дуусах хүртэл
                printf("%s\t", current->student_id);
                current = current->next;
            }

            printf("\n");
        }
    }
}
