#ifndef STUDENT_H
#define STUDENT_H

#define NUM_STUDENTS 10
#define NUM_GRADES 5

typedef struct {
char name[50];
int kurs;
int ses[NUM_GRADES];
} Student;

void input_s(Student *s, int index);
void print_s(const Student *s);
float average_g(const Student *s);
int compar_n(const void *a, const void *b);
float total_a(const Student arr[], int n);

#endif
