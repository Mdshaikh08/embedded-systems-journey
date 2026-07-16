#include<stdio.h>


typedef void (*Eventhandler)(void);

Eventhandler registered_handler = NULL;

void Registered_Handler(Eventhandler handler){
    registered_handler = handler;
}

void Trigger_Event(void){
    if(registered_handler != NULL){
        registered_handler();
    }
    else{
        printf("No Event Registered!\n");
    }
}

void My_Handler(void){
    printf("Event Handled!\n");
}


int main(){
    Trigger_Event();
    Registered_Handler(My_Handler);
    Trigger_Event();
}