#include<stdio.h>
#include<stdint.h>


typedef struct {
    uint8_t output_enable : 1;
    uint8_t output_value  : 1;
    uint8_t mode          : 2;
    uint8_t reserved      : 4;
} GPIO_CR;

   void gpio_set_output(GPIO_CR *reg);
   void gpio_set_input(GPIO_CR *reg);
   void gpio_set_mode(GPIO_CR *reg , uint8_t mode);
   void gpio_print(GPIO_CR *reg);


int main(){
     GPIO_CR reg = {0};   
    gpio_print(&reg);
    gpio_set_output(&reg);
    gpio_print(&reg);
    gpio_set_mode(&reg, 1);  
    gpio_print(&reg);
}

void gpio_print(GPIO_CR *reg){
   printf(" output enable : %d \n output_value : %d \n mode : %d \n reserved : %d \n" , reg->output_enable, reg->output_value, reg->mode, reg->reserved)   ;
}

void gpio_set_input(GPIO_CR *reg){
    reg->output_enable = 0;
    reg->output_value = 0;
}

void gpio_set_output(GPIO_CR *reg){
    reg->output_enable = 1;
    reg->output_value= 1;
}

void gpio_set_mode(GPIO_CR *reg , uint8_t mode){
     reg->mode = mode;
}