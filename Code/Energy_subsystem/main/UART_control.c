/*
 * UART_control.c
 *
 * Created: 12/05/2023 22:47:08
 *  Author: danie
 */

void UART_init()
{
	// Using UART0 in Full duplex mode
	// 1. Set the baud rate (USARTn.BAUD).
	// 2. Set the frame format and mode of operation (USARTn.CTRLC).	-	8 data bits, even parity, 1 stop bit
	// 3. Configure the TXD pin as an output.
	// 4. Enable the transmitter and the receiver (USARTn.CTRLB).
}

uint8_t UART_transmit(uint8_t *data, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		// write data to buffer
		UART0.TXDATAL = data[i];
		// wait for buffer to be empty
		while (!(UART0.STATUS & USART_DREIF_bm))
			;
	}
}