// This is how embedded code reads raw bytes from hardware
// and interprets them as a float
#include<stdio.h>
#include<stdint.h>


typedef union {
    float f ;
    uint32_t i; 
    uint8_t byte[4];
} FloatBytes;

int main(){

    FloatBytes fb;
   fb.i = 0x40490FDB;

    for (int i = 0; i < 4; i++)
    {       
        printf("byte[%d] = 0x%02X\n " , i , fb.byte[i]);
    }

    printf("as float : %.6f\n" , fb.f);
    

}