#include<stdio.h>
#include<stdint.h>
#include<windows.h>


typedef struct {
    volatile uint32_t PDOR;
    volatile uint32_t PSOR;
    volatile uint32_t PCOR;
    volatile uint32_t PDDR;
} GPIO_TYPE;


static GPIO_TYPE fake_gpio_hw;
GPIO_TYPE *GPIO = &fake_gpio_hw;

CRITICAL_SECTION cs;

#define NUM_TOGGLES 100000


void gpio_toggle_pin_unsafe(GPIO_TYPE *base, uint32_t pin){
    base->PDOR ^= (1U << pin);
}

void gpio_toggle_pin_safe(GPIO_TYPE *base, uint32_t pin){
    EnterCriticalSection(&cs);
    base->PDOR ^= (1U << pin);
    LeaveCriticalSection(&cs);

}

DWORD WINAPI isr_simulation(LPVOID arg){
    for (int i = 0; i < NUM_TOGGLES; i++)
    {
        gpio_toggle_pin_unsafe(GPIO , 5);
    }
    return 0;
    
};

int main(void) {
     InitializeCriticalSection(&cs);

    HANDLE isr_thread = CreateThread(NULL, 0, isr_simulation, NULL, 0, NULL);

    for (int i = 0; i < NUM_TOGGLES; i++) {
        gpio_toggle_pin_unsafe(GPIO, 5);   
    }

    WaitForSingleObject(isr_thread, INFINITE);
    CloseHandle(isr_thread);
    DeleteCriticalSection(&cs);

   printf("Final PDOR bit 5 state: %lu\n", ((GPIO->PDOR >> 5) & 1));

    return 0;


}