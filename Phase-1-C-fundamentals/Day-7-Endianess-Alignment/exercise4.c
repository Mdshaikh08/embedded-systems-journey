#include<stdint.h>
#include<stdio.h>


struct CAN_Frame_Normal
{
    uint32_t id;
    uint8_t dlc;
    uint8_t data[8];
};

struct __attribute__((packed)) CAN_Frame_Packed
{
    uint32_t id ;
    uint8_t dlc;
    uint8_t data[8];
};


int main(){
    printf("Normal size : %zu bytes \n", sizeof(struct CAN_Frame_Normal) );
    printf("Packed size : %zu bytes \n" , sizeof(struct CAN_Frame_Packed));

    struct CAN_Frame_Packed frame =
    {
        .id = 0x1FFFFFFF,
        .dlc = 3,
        .data = {0xAA , 0xBB , 0xCC}
    };

    uint8_t *raw = (uint8_t *)&frame;
    for (int i = 0; i < sizeof(frame); i++)
    {
        printf("byte[%d] = 0x%02X\n" , i , raw[i]);
    }
    
    
}

