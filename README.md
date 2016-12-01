# nRF24L01
This is a wireless RF Transceiver project, the Microcontroller is a PIC16F87XA. The software is written and uploaded through MPLab. 


All I/O is configured specicaly for the above Microcontroller.

Datasheets: 

http://ww1.microchip.com/downloads/en/DeviceDoc/39582b.pdf

https://www.sparkfun.com/datasheets/Components/SMD/nRF24L01Pluss_Preliminary_Product_Specification_v1_0.pdf

Currently there is no distinction mechanism between RX and TX packet flow. The program works as a packet transmitter, modules uses standard SPI layout. The main.c file contains code pertaining to RX more so than TX. 

