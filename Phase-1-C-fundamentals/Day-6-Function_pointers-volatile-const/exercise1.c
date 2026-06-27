#include<stdio.h>
#include<stdlib.h>


// typedef int (*operation)(int , int);

int add(int a , int b){
    return a+b;
}
int sub(int a , int b){
    return a-b;
}
int mul(int a , int b){
    return a*b;
}


int main(){
    int (*operation)(int , int);

    operation = &add;
    printf("add : %d\n", operation(5 , 3));

    operation = &sub;
    printf("Sub : %d\n" , operation(5 , 3));

    operation = &mul;
    printf("Mul : %d\n" , operation(5 , 3));
}