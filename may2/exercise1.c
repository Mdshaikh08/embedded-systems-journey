#include<stdio.h>

int main(){
    int a = 10 , b = 20;
    int *p = &a;
    *p = 30;
    p = &b;
    *p += 5;

    printf("%d %d\n" , a,b);

}