#include<stdio.h>
#include<stdint.h>



uint32_t byteswap_32(uint32_t val){
    return ((val & 0xFF)<<24) | (((val >> 8) & 0xFF)<<16) | (((val >> 16) & 0xFF)<<8) | (((val >> 24) & 0xFF));
}

uint16_t byteswap_16(uint16_t val){
    return ((val & 0xFF)<< 8) | ((val >> 8) & 0xFF);
}


int main(){
    printf("0x%08X\n" , byteswap_32(0x12345678));
    printf("0x%04X\n", byteswap_16(0x1234)); 
}