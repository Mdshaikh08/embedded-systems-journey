#include<stdio.h>
#include<stdint.h>



#define UART_EN_BIT    0
#define UART_TX_BIT    1
#define UART_RX_BIT    2
#define UART_PAR_BIT   3
#define UART_BAUD_MASK 0x30  // 00110000
#define UART_STOP_BIT  6

uint8_t uart_init(int tx, int rx, int par, uint8_t baud, int stop){
    // enable uart
    uint8_t reg = (1 <<UART_EN_BIT);

    if(tx){
        reg |= (1<<UART_TX_BIT) ;
    }

    if (rx)
    {
        reg |= (1<<UART_RX_BIT);
    }

    // parity 
    if (par)
    {
        reg |= (1<<UART_PAR_BIT);
    }
    

    // set the baud value
    reg |= ((baud & 0x03) << 4);
    
    if (stop)
    {
       reg |= (1<<UART_STOP_BIT);
    }

    return reg;
    
}

void uart_print_config(uint8_t reg){
    // bit 0
    printf("Enabled : %s\n", (reg & 1)? "Yes" : "No" );

    // bit 1
    printf("TX : %d\n", ((reg >> UART_TX_BIT) & 1));

    // bit 2
    printf("RX : %d\n" , ((reg >> UART_RX_BIT ) & 1));

    //bit 3
    printf("Parity : %d\n" , ((reg >> UART_PAR_BIT) & 1));

    //bit 4-5
    printf("Baud Rate : %d\n" , (reg & UART_BAUD_MASK)>> 4);

    //bit 6
    printf("Stop Bit : %d\n" , ((reg >> UART_STOP_BIT) & 1));
}



int main(){
    uint8_t reg = uart_init(1, 1, 0, 3, 1);
    // printf("%d" , reg);

    uart_print_config(reg);

}