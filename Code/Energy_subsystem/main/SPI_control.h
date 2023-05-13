/*
 * SPI_control.h
 *
 * Created: 12/05/2023 22:40:30
 *  Author: danie
 */ 


#ifndef SPI_CONTROL_H_
#define SPI_CONTROL_H_

void SPI_init();
uint8_t SPI_write(uint8_t addr, uint8_t data);
uint8_t SPI_read(uint8_t addr);


#endif /* SPI_CONTROL_H_ */