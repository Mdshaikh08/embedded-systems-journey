#include<stdio.h>
#include<stdint.h>

uint8_t kernighan_count(uint8_t);
void table_fill(uint8_t*);
uint8_t bit_count(uint32_t);

uint8_t table[256];


int main(){
    table_fill(table);
    // printf("%d" ,table[2] );

    uint8_t bits = bit_count(31);
    printf("The total bits : %d" , bits);
    


}

uint8_t bit_count(uint32_t no){
   return table[(no) & 0xFF] + table[(no>>8) & 0xFF] + table[(no>>16) & 0xFF] + table[no>>24];
}


void table_fill(uint8_t *table){
    for (uint16_t i = 0; i < 256; i++){
        *table = kernighan_count(i);
        table++;
    }
}

uint8_t kernighan_count(uint8_t no){
    uint8_t count = 0;
    while (no != 0)
    {
        no = (no) & (no - 1);
        count++;
    }

    return count;
    
}