#include<stdio.h>
#include<stdint.h>



void int_to_binary_string(int n, char *out){
    uint8_t bit ;
    for(int i = 31; i >= 0 ;i--){
        bit = (n & 1);
        out[i] = bit + '0';
        n = n >>1;
    }
    out[32] = '\0';
}

int main(void) {
    char buf[33];  // 32 bits + null terminator
    int_to_binary_string(5, buf);
    printf("%s\n", buf);  // expect: 00000000000000000000000000000101
}