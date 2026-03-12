#include <stdio.h>
#include <string.h>
#include "student.h"

void input_s(Student *s, int index) {
    printf("Введите данные для студента #%d:\n", index + 1);
    printf("Фамилия и инициалы: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;

    printf("Курс: ");
    scanf("%d", &(s->kurs));

    printf("Оценки (5 штук через пробел): ");
    for (int i = 0; i < NUM_GRADES; i++) {
        scanf("%d", &(s->ses[i]));
    }
    while (getchar() != '\n');
}

void print_s(const Student *s) {
    printf("%-30s  Курс: %2d  Оценки: ", s->name, s->kurs);
    for (int i = 0; i < NUM_GRADES; i++) {
        printf("%d ", s->ses[i]);
    }
    printf(" Средний балл: %.2f\n", average_g(s));
}

float average_g(const Student *s) {
    int sum = 0;
    for (int i = 0; i < NUM_GRADES; i++) {
        sum += s->ses[i];
    }
    return (float)sum / NUM_GRADES;
}

int compar_n(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return strcmp(studentA->name, studentB->name);
}

float total_a(const Student arr[], int n) {
    float total = 0.0;
   for (int i = 0; i < n; i++) {
        total += average_g(&arr[i]);
    }
    return total / n;
}
