
#include <plib.h> 
#include <> 

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma cpragmaonfig POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_8

#define SYS_FREQ            (80000000L)

// Chip Config 
#pragma config FOSC = HS; 
#pragma config WDTE = ON; 
#pragma config PWRTE = OFF;
#pragma config BOREN = ON;  
#pragma config LVP = OFF; 
#pragma config CPD = OFF;
#pragma config WRT = OFF;  
#pragma config CP = OFF;

int main(void) {    //Main Void: While
  TRISB0 = 0; 
  while(1) {
    RB0 = 1; RB2 = 0; 
    __delay_ms(1000);
    RB0 = 0; RB2 = 1;
    __delay_ms(1000); 
  }
  
  return 0;
}




