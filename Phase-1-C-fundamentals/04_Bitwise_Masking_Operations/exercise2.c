#include<stdio.h>
#include<stdint.h>
/*
#define GET_BIT(reg , n) ((reg>>n) & (1))
int count_bits(uint32_t);
int is_pow_of_two(uint32_t);


int main(){
   uint8_t no_of_1s = count_bits(33);
   uint8_t result =  is_pow_of_two(no_of_1s);
}

int count_bits(uint32_t no){
    uint8_t sum = 0;
    uint8_t bit ;
    for (int n = 0; n < 32; n++ ){
       
       if((bit = GET_BIT(no , n)) == 1)
       {
        sum++;
       }
       
    }
  return sum;

}

int is_pow_of_two(uint32_t no_of_bits){

    if (no_of_bits==1)
    {
        printf("The given no is power of 2");
        return 1;
    }
    else 
    {   printf("The given no is not the power of 2");
        return 0;
    }
}
    */
/*
int find_unique(int *,  int );


int main(){
    int arr[5] = {1, 2, 3, 2, 1};
    uint8_t unique =  find_unique(arr , 5);
}

int find_unique(int *arr ,  int n){
    int i = 0;
    uint8_t and_op = arr[i];
    while(i+1 < n)
    { 
        i++;
        and_op ^= arr[i];
    }
    return and_op;
   
}

*/
/*
uint32_t reverse_bits(uint32_t n );

int main(){
    uint32_t reversed = reverse_bits(34);
    // 00100010

}

uint32_t reverse_bits(uint32_t n ){
    uint32_t result = 0b00000000000000000000000000000000;
                  //  0b00000000000000000000000000100010;
                  //  0b01000100000000000000000000000000;
    for (int i = 0; i < 32; i++)
    {
        result =(result<<1);
        result = result | (n & 1) ;
        n >>= 1;

    }

   return result;
    
}
   */

  void swap_bits(int *a, int *b);

  int main(){
     int x = 5, y = 10;
    swap_bits(&x, &y);
    printf("%d %d\n", x, y);
  }

  void swap_bits(int *a , int *b ){
    *b = *a ^ *b ;
    *a = *a ^ *b;
    *b = *b ^ *a;
    
  }