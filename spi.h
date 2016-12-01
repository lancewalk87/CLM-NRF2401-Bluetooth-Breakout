#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

void SPI_Init(); //Intializes SPI 
unsigned char SPI_Send(unsigned char data);

#ifdef	__cplusplus
}
#endif

#endif	