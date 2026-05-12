#include<stdio.h>

typedef struct 
{
    char name[20];
    int age;
    float gpa;
} student;


void print_student(student *);
void update_age(student *);
void update_gpa(student * , float);

int main(){
  student s1 = {"Adnan", 21, 8.5};
  print_student(&s1);
  update_age(&s1);
  update_gpa(&s1 , 9.0);
  print_student(&s1);
}

void print_student(student *s){
    printf("Name : %s \nAge : %d \ngpa : %.2f\n" , s->name , s->age , s->gpa );
}

void update_age(student *s){
    ++s->age;
    // printf("%d" , s->age);

}

void update_gpa(student *s , float gpa){
    s->gpa = gpa;
    // printf("%.2f" , s->gpa);
}