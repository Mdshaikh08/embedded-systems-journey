#include<stdio.h>
#include<stdint.h>

// Brian kernighan algo

uint8_t kernighan_count(uint32_t);   

int main(){
uint32_t no = 127;

uint8_t n = kernighan_count(no);

printf("Total no of bits : %u" , n);


    
}

uint8_t kernighan_count(uint32_t no){
uint8_t count = 0;

while (no != 0)
{
    no = (no) & (no-1);
    count++;

}

return count;

}