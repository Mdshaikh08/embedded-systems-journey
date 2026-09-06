#include<stdio.h>
#include<stdint.h>


typedef struct{
    volatile uint32_t   PDOR;
    volatile uint32_t   PSOR;
    volatile uint32_t   PCOR;
    volatile uint32_t   PDDR;
}GPIO_TYPE;

static GPIO_TYPE fake_gpio_hw;
GPIO_TYPE *GPIO = &fake_gpio_hw;


void gpio_set_pin(GPIO_TYPE *base, uint32_t pin);     // uses PSOR to set pin high
void gpio_clear_pin(GPIO_TYPE *base, uint32_t pin);   // uses PCOR to clear pin low
void gpio_toggle_pin(GPIO_TYPE *base, uint32_t pin);  // read PDOR, XOR the bit, write back — NOT atomic, note this
void gpio_set_direction(GPIO_TYPE *base, uint32_t pin, int output);  // sets PDDR bit

int main(void) {
    gpio_set_direction(GPIO, 5, 1);   // pin 5 as output
    gpio_set_pin(GPIO, 5);
    gpio_clear_pin(GPIO, 5);
    gpio_toggle_pin(GPIO, 5);
    // print PDOR/PDDR values after each step to confirm
}

void gpio_set_pin(GPIO_TYPE *base , uint32_t pin){
    base->PSOR = (1U << pin);
    base->PDOR |= (1U << pin);
    printf("%d " , base->PSOR);
}

void gpio_clear_pin(GPIO_TYPE *base, uint32_t pin){
    base->PCOR = (1U << pin);
    base->PDOR &= ~(1U << pin);
    printf("%d " , base->PDOR);
}

void gpio_toggle_pin(GPIO_TYPE *base, uint32_t pin){
     base->PDOR ^= (1U << pin);
     printf("%d " , base->PDOR);
}

void gpio_set_direction(GPIO_TYPE *base, uint32_t pin, int output){
    if(output){
    base->PDDR |= (1U << pin);
    }
    else{
        base->PDDR &= ~(1U << pin);
    }
    printf("%d " , base->PDDR);
}

