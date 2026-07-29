#include<stdio.h>


#define Stack_Size 8

typedef struct {
    int data[Stack_Size];
    int top;
}stack;


void stack_init(stack *s);
int stack_is_full(stack *s);
int stack_is_empty(stack *s);
int stack_push(stack *s , int value);
int stack_pop(stack *s , int *out);

int main(){
    stack s;
    stack_init(&s);

    for (int i = 1; i <= 10; i++)
    {
        int temp = stack_push(&s , i*10);
        printf("push %d: %s\n" , i*10 , temp ? "OK" : "FULL");
    }
    

    int val;
    while (stack_pop(&s , &val))
    {
        printf("Popped %d\n" , val);
    }
    
}


void stack_init(stack *s){
    s->top = -1;
}

int stack_push(stack *s , int value){
    if (stack_is_full(s))
    {
        return 0;
    }

    (s->top)++;
    s->data[s->top] = value;

    return 1;
    
}

int stack_is_full(stack *s){
    if (s->top == Stack_Size -1)
    {
        return 1;
    }

    return 0;
    
}

int stack_pop(stack *s , int *out){
    if (stack_is_empty(s))
    {
        return 0;
    }

    *out = (s->data[s->top]);
    (s->top)--;

    return 1;
    
}

int stack_is_empty(stack *s){
    if (s->top == -1)
    {
        return 1;
    }

    return 0;
    
}
