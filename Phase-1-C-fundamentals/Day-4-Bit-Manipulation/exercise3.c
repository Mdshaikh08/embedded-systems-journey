// Simulate setting up a UART register
// Bit 0   = enable UART (1=on)
// Bit 1   = TX enable
// Bit 2   = RX enable  
// Bit 3   = parity enable
// Bit 4-5 = baud rate select (00=9600, 01=19200, 10=38400, 11=115200)
// Bit 6   = stop bits (0=1 stop bit, 1=2 stop bits)
// Bit 7   = reserved

#define UART_EN_BIT    0
#define UART_TX_BIT    1
#define UART_RX_BIT    2
#define UART_PAR_BIT   3
#define UART_BAUD_MASK 0x30   // bits 4-5
#define UART_STOP_BIT  6

// Implement:
uint8_t uart_init(int tx, int rx, int parity, uint8_t baud, int stop_bits);
// Returns the configured register value

void uart_print_config(uint8_t reg);
// Print each field's value

int main() {
    // Configure: TX on, RX on, no parity, 115200 baud, 1 stop bit
    uint8_t reg = uart_init(1, 1, 0, 3, 0);
    uart_print_config(reg);
    // Expected: UART enabled, TX=1, RX=1, parity=0, baud=11, stop=0
}           