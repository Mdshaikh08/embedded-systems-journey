#include<stdio.h>

int main(){
    char log[25];
    int time = 2;
    snprintf(log , sizeof(log) , "The update was at %d PM" , time);
    printf("%s ", log);
}