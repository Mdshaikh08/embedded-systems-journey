#include<stdio.h>


typedef enum {Red , Green , Yellow} State;

typedef State (*StateHandler)(void);


State handle_Red(void);
State handle_Green(void);
State handle_Yellow(void);


int main(){
    StateHandler State_Arr[] = {handle_Red , handle_Green , handle_Yellow};

    State Current = Red;

    for (int i = 0; i < 6; i++)
    {
        printf("State : %d\n" , Current);
        Current = State_Arr[Current]();   
    }
    
    return 1;
}

State handle_Red(void){
    printf("Red -> Green\n");
    return Green;
}

State handle_Green(void){
    printf("Green -> Yellow\n");
    return Yellow;
}

State handle_Yellow(void){
    printf("Yellow -> Red\n");
    return Red;
}