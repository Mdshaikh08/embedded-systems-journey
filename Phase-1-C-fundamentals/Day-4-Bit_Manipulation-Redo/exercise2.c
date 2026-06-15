#include<stdio.h>
#include<stdint.h>

#define GET_BIT(no) ((no) & 1)
int count_bits(uint32_t);


int main(){

   uint8_t count  = count_bits(113);
   printf("Total no of bits : %d" , count);
}

int count_bits(uint32_t no){

    uint8_t sum = 0;
    while(no != 0) {
        if (GET_BIT(no) == 1)
        {
            sum++;
        }
        no >>= 1;
        
    }
        return sum;
    }
