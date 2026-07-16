#include<stdio.h>
#include<stdint.h>

uint8_t power(uint32_t no){
    return (no != 0) && (((no) & (no -1)) == 0);
    
}

int main(){
   uint8_t ans = power(3);
   printf("The no is power of 2 ");
   if(ans == 1)
   {
    printf(": true");
   }
   else{
    printf(": false");
   }
   

}