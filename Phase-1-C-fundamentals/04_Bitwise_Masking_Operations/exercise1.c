#include<stdio.h>
#include<stdint.h>

#define SET_BIT(reg , n) reg |= (1<<n)
#define CLR_BIT(reg , n) reg &= ~(1<<n)
#define TOG_BIT(reg , n) reg ^= (1<<n)
#define GET_BIT(reg , n) (reg>>n) & 1

int main(){
    uint8_t reg = 0b00000000;

    SET_BIT(reg , 3);
    printf("After SET bit 3  : 0x%02X\n" , reg);

    CLR_BIT(reg, 3);
    printf("After CLR  bit 3: 0x%02X\n", reg);

    SET_BIT(reg, 1);
    SET_BIT(reg, 5);
    TOG_BIT(reg, 1);
    TOG_BIT(reg, 7);
    printf("After TOG  bits:  0x%02X\n", reg);  

    printf("GET bit 7: %d\n", GET_BIT(reg, 7)); 
    printf("GET bit 0: %d\n", GET_BIT(reg, 0));



}