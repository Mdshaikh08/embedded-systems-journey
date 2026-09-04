#include<stdio.h>
#include<stdint.h>


int reverse_bits(unsigned int no){

    unsigned int ret = 0;
    for (int i = 0; i < 32; i++)
    {
       ret =  ((no >> i) & 1) | (ret << 1) ;
    }
    
    return ret;
}


int main(){
    unsigned int reverse;
    reverse = reverse_bits(31);

    printf("%u " , reverse);
}