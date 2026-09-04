#include<stdio.h>
#include<stdint.h>

uint8_t kernigahn_count(unsigned int n){
    uint8_t sum = 0;

    while(n != 0){

        sum++;
        n = (n) & (n-1);
    }

    return sum;
}

int main(){
    int no = kernigahn_count(31);

    printf("%d " , no);
}