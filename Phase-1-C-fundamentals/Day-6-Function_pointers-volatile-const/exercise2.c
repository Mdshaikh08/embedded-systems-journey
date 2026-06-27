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
    int (*operation[3])(int , int) = {add , sub , mul};

    char *names[3] = {"add" , "sub" , "mul"};

    for (int i = 0; i < 3; i++)
    {
        printf("%s : %d\n", names[i] , operation[i](5 , 3));
    }
    
   

    

    
}