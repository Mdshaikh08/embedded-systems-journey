#include<stdio.h>

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
    int (*operation)(int , int );

    operation = &add;
    printf("Add : %d\n" , operation(3 , 4));

    operation = &sub;
    printf("Sub : %d\n" , operation(4 , 3));

    operation = &mul;
    printf("Mul : %d\n" , operation(3 , 4));


}