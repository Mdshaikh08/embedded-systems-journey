#include<stdio.h>
#include<stdint.h>


#define SIZE 256
uint8_t lookup[SIZE];


uint8_t kernigahn(unsigned int n){
    uint8_t sum = 0 ;

    while(n != 0){

        sum++;
        n = (n) & (n-1);

    }
    // printf("%d " , sum);
    return sum;
}

void fill_table(void){
    for(int i = 0 ; i < SIZE ; i++){
        lookup[i] = kernigahn(i);
    }
}



uint8_t count_bits(unsigned int no){
    uint8_t sum = 0;

    sum = lookup[no & 0xFF] + lookup[(no >> 8)  & 0xFF] + lookup[(no >> 16) & 0xFF] + lookup[(no >> 24) & 0xFF];

  
    return sum;
}


int main(){
    int no_of_bits ;

    fill_table();

    no_of_bits = count_bits(255);

    printf("%d " , no_of_bits);


}