#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student students[NUM_STUDENTS];

    printf("Ввод информации о %d студентах:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        input_s(&students[i], i);
    }

    qsort(students, NUM_STUDENTS, sizeof(Student), compar_n);
    printf("\n Отсортированный список всех студентов\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        print_s(&students[i]);
    }

    float avgTotal = total_a(students, NUM_STUDENTS);
    printf("\n Общий средний балл всех студентов: %.2f \n", avgTotal);
    printf("\n Студенты с баллом выше общего среднего\n");
    int found = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (average_g(&students[i]) > avgTotal) {
            print_s(&students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Таких студентов нет.\n");
    }

    return 0;
}
