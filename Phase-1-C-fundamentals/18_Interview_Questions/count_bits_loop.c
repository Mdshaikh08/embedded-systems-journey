#include<stdio.h>
#include<stdint.h>

uint8_t count_bits_loop(unsigned int n){
    uint8_t sum = 0;
    for(int i = 0; i < 32; i++){
        if(((n >> i) & 1) == 1){
            sum++;
        }
    }

    return sum;
};


int main(){
    int n = count_bits_loop(31);
    printf("%d " , n);
}