#include<stdio.h>
#include<stdint.h>


uint32_t reverse(uint32_t no){
    uint32_t rev_no = 0;
    for (uint8_t i = 0; i < 32; i++)
    {
        rev_no = rev_no<< 1  | ((no) & 1);
        no >>= 1;
    }
    return rev_no;
    

}

int main(){
    uint32_t no = 1;
    uint32_t rev_no = reverse(no);
    printf("%d" , rev_no);
}