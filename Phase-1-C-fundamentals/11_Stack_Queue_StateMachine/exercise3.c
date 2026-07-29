#include<stdio.h>
#include<stdint.h>

#define Stack_Size 64

static unsigned char stack[Stack_Size];
static int top = -1;

void Reversed_byte(unsigned char *input , unsigned char *output , int len);
void stack_push(unsigned char *input);
void stack_pop(unsigned char *output);


int main(){
    unsigned char input[] = "Embedded";
    unsigned char output[9];
    int len = 8;

    Reversed_byte(input , output , len);
    output[len] = '\0';

    printf("Previous : %s\n" , input);
    printf("Current : %s\n" , output);

}


void Reversed_byte(unsigned char *input , unsigned char *output , int len){

    for (int i = 0; i < len; i++)
    {
        stack_push(&input[i]);
    }

    for (int i = 0; i < len; i++)
    {
        stack_pop(&output[i]);
    }
}

void stack_push(unsigned char *input){

    if (top == Stack_Size - 1)
    {
        printf("Stack Overflow!");
        return;
    }
    
    top++;
    stack[top] = *input;     
    
    }

void stack_pop(unsigned char *output){

    if (top < 0)
    {
        printf("Stack Underflow!");
        return;
    }
    
    *output = stack[top];
    top--;
}