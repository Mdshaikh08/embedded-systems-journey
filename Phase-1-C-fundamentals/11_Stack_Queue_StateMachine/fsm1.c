#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>


typedef enum {
    State_Locked,
    State_Unlocked
}GateState;

GateState currentState = State_Locked;


void process_gate_fsm(int inputAction){

    switch(currentState){
        case State_Locked:
        if(inputAction == 1){
            currentState = State_Unlocked;
            printf("[GATE] Coin accepted! Gate is now UNLOCKED. You can pass.\n");
        }
        else if(inputAction == 2){
            printf("[GATE] Access Denied! The gate is LOCKED. Please insert a coin.\n");
        }
        break;

        case State_Unlocked:
        if (inputAction == 1)
        {
             printf("[GATE] Coin returned. The gate is already UNLOCKED.\n");
        }
        else if(inputAction == 2){
            currentState = State_Locked;
            printf("[GATE] You pushed through. Gate is now LOCKED behind you.\n");
        }
        break;
        
    }
}

int main(){

    int choice;       
    printf("--- Metro Gate FSM Simulator ---\n");
    printf("Initial State: LOCKED\n");
    printf("Options: 1 = Insert Coin, 2 = Push Gate, 0 = Exit\n");


    while(1){
        printf("\nYour Action (1 or 2): ");
        if(scanf("%d", &choice) != 1 || choice == 0){ 
   
            break;
        }

        if(choice == 1 || choice == 2){
            process_gate_fsm(choice);
        }
        else{
             printf("Invalid action. Use 1 (Coin) or 2 (Push).\n");
        }
    }

    printf("Simulation ended.\n");
    return 0;
}