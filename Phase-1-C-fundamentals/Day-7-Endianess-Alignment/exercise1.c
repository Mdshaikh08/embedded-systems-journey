#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


int is_little_endian(){
    union abc
    {
        uint32_t x ;
        uint8_t y[4];
    }b;

   b.x= 0x12345678;

   if (b.y[0] == 0x12) return 0;
   else if(b.y[0] == 0x78) return 1;
   printf("Undefined endianess !");
   return -1;
    
}


int main(){
    uint8_t result = is_little_endian();
    if (result == 1)
    {  printf("LITTLE ENDIAN"); }
    else if(result == 0){ printf("BIG ENDIAN"); } 
    else{ printf("UNDEFINED ENDIANESS");}

    
}