#include<stdio.h>

int main(){
    struct A {
    char  a;      // 1 byte
    int   b;      // 4 bytes
    char  c;      // 1 byte
};

struct B {
    int   b;      // 4 bytes
    char  a;      // 1 byte
    char  c;      // 1 byte
};

struct C {
    char  a;      // 1 byte
    char  c;      // 1 byte
    int   b;      // 4 bytes
};

printf("%zu\n", sizeof(struct A));   
printf("%zu\n", sizeof(struct B));    
printf("%zu\n", sizeof(struct C));  
}