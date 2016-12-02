
#include <plib.h> 

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma cpragmaonfig POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_8

#define SYS_FREQ            (80000000L)
#include <xc.h>

#pragma config FOSC = INTRC_NOCLKOUT, WDTE = OFF, PWRTE = OFF, MCLRE = OFF
#pragma config CP = OFF, CPD = OFF, BOREN = OFF, IESO = OFF, FCMEN = OFF
#pragma config LVP = OFF, DEBUG = OFF
#pragma config BOR4V = BOR40V, WRT = OFF

#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 8000000 //Clock 80MhZ
    #define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/8000000.0)))
    #define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/8000.0)))
#endif

#include "spi.h"
// Additional Config
void Init(void);
void transmit_data(void);
void configure_transmitter(void);
unsigned char spi1_send_read_byte(unsigned char byte);

#define SPI_SCK		RC3		
#define SPI_SO		RC5		// Serial out
#define SPI_SI		RC4		// Serial in
#define SPI_CSN		RC2		// CSN 
#define SPI_CE		RC1		// CE 
#define SPI_SCALE	4               
#define PB		RA1

void main(){
    Init(); //initialize program
    SPI_Init();
    config();
    //RA0 (RX)
    //RA1 (TX)
    while(1) { //Toggle 
        transmit_data();
        
        RA0 = 1;
        __delay_ms(500);			
        RA0 = 0;
        __delay_ms(3270);	

        // RA1 TX incomplete
    }
}

void Init(void) {
	PORTA = 0x00;
	ADCON1 = 0x0F;		
	TRISA = 0x02;		
	TRISBbits.TRISB0 = 1;	// IRQ in
	TRISCbits.TRISC1 = 0;	// CE out
	TRISCbits.TRISC2 = 0;	// CSN out
}

void config(void) {
    unsigned char i, j, data, cmd;

    SPI_CE = 0;
    SPI_CSN = 0;

 	SPI_Send(0x20);
  	SPI_Send(0x38);
	SPI_CSN = 1;
    SPI_CSN = 0;

 	SPI_Send(0x24);
   	SPI_Send(0x00);
    SPI_CSN = 1;
    SPI_CSN = 0;

    //Bandwidth Config
   	SPI_Send(0x23);
 	SPI_Send(0x03);
    SPI_CSN = 1;
    SPI_CSN = 0;

	//data rate = 1MB
   	SPI_Send(0x26);
 	SPI_Send(0x07);
    SPI_CSN = 1;
    SPI_CSN = 0;
   	SPI_Send(0x25);
 	SPI_Send(0x02);
    SPI_CSN = 1;
    SPI_CSN = 0; 

   	SPI_Send(0x30);
    for (j = 0; j < 5; j++) {

        SPI_Send(0xE7);
    }
    SPI_CSN = 1;
    SPI_CSN = 0;

   	SPI_Send(0x21);
 	SPI_Send(0x00);
    SPI_CSN = 1;
}

void transmit_data(void) {
    unsigned char a, data, cmd;

    SPI_CSN = 0;
    //Clear cache
    SPI_Send(0x27);
    SPI_Send(0x7E);
    SPI_CSN = 1;
    SPI_CSN = 0;

    SPI_Send(0x20);
    SPI_Send(0x3A);
    SPI_CSN = 1;
    SPI_CSN = 0;

    SPI_Send(0xE1);
    SPI_CSN = 1;
    SPI_CSN = 0;

    SPI_Send(0xA0);
    SPI_Send(0x34);
    SPI_Send(0x33);
    SPI_Send(0x32);
    SPI_Send(0x31);
    SPI_CSN = 1;

    //Start up 
    SPI_CE = 1;
    __delay_ms(69);			//delay 69 ms
    SPI_CE = 0;
}
