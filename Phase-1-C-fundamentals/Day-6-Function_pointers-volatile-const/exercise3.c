#include<stdio.h>
#include<stdlib.h>

typedef void (*Eventhandler)(void);

Eventhandler registered_handler = NULL;

void Register_handler(Eventhandler handler){
    registered_handler = handler;
}

void trigger_event(){
    if (registered_handler != NULL)
    {
        registered_handler();
    }
    else
    {
        printf("No Handler Registered\n");
    }
    
    

}

void my_handler(){
    printf("Event handled!\n");
}


int main(){
    trigger_event();
    Register_handler(my_handler);
    trigger_event();
}