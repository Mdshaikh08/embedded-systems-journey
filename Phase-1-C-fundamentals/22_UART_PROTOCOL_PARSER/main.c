#include<stdio.h>
#include<stdint.h>

#include "Ring_Buffer.h"

#define FIXED_TEXT 0xAA

uint8_t packet[] = {FIXED_TEXT, 0X03, 0X10, 0X20, 0X30, 0x00};

int main(){

    CircularBuffer rb;
    cb_init(&rb);

    for(size_t i = 0 ; i < sizeof(packet) ; i++){
        cb_enqueue(&rb , packet[i]);
    }

    int val;
    while(cb_dequeue(&rb , &val)){
        printf("0x%02X " , val);
    }
}



