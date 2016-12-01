#include <xc.h>
#include "spi.h"

void SPI_Init() {

    TRISC3 = 0;         
    TRISC4 = 1;         
    TRISC5 = 0; //Serial Out         

    SMP = 0;            
    CKP = 1;            
    CKE = 0;           

    SSPEN = 1;         
    SSPIF = 0;

    SSPM3 = 0;          //
    SSPM2 = 0;          //
    SSPM1 = 0;          //
    SSPM0 = 1;          

}

unsigned char SPI_Send(unsigned char data) {
    SSPBUF = data;          
    while (!BF);           
    return SSPBUF;          // SPI saves char upon return 
}