/*
 * SPI_control.c
 *
 * Created: 12/05/2023 22:40:14
 *  Author: danie
 */ 

void SPI_init(){	// TODO THIS IS NOT DONE
	// Using SPI0
	// Configure the SS pin in the port peripheral.
	// Select the SPI master/slave operation by writing the Master/Slave Select (MASTER) bit in the Control A (SPIn.CTRLA) register.
	SPI0.CTRLA |= SPI_MASTER_bm;
	// In Master mode, select the clock speed by writing the Prescaler (PRESC) bits and the Clock Double (CLK2X) bit in SPIn.CTRLA.
	// Optional: Select the Data Transfer mode by writing to the MODE bits in the Control B (SPIn.CTRLB) register.
	// Optional: Write the Data Order (DORD) bit in SPIn.CTRLA.
	// Optional: Set up the Buffer mode by writing the BUFEN and BUFWR bits in the Control B (SPIn.CTRLB) register.
	// Optional: To disable the multi-master support in Master mode, write �1� to the Slave Select Disable (SSD) bit in SPIn.CTRLB.
	// Enable the SPI by writing a �1� to the ENABLE bit in SPIn.CTRLA
}

uint8_t SPI_write(uint8_t addr, uint8_t data){
	uint8_t data_out;
	// TODO Select the slave by pulling the SS pin low.
	// Write the data to the Data Register (SPIn.DATA).
	SPI0.DATA = data;
	// Wait for the transfer to complete by polling the Interrupt Flag (IF) bit in the Status Register (SPIn.INTFLAGS).
	while (!(SPI0.INTFLAGS & SPI_IF_bm))
		;
	// Read the received data from the Data Register.
	data_out = SPI0.DATA;
	// TODO Deselect the slave by pulling the SS pin high.
	return data_out;
}

uint8_t SPI_read(uint8_t addr){
	
}