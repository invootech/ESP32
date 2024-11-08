/*
  LED Forward and Backward Chaser Program
  This program turns on and off LEDs connected to digital pins 
  14, 27, 26, 25, 33, and 32 of an ESP32 microcontroller. The LEDs 
  first glow sequentially from LED 1 (pin 14) to LED 6 (pin 32), then 
  reverse direction, glowing sequentially from LED 6 back to LED 1. 
  Each LED lights up for 150 milliseconds before turning off, creating 
  a forward and backward chaser effect.
  Pin assignments:
    Pin 14: LED 1
    Pin 27: LED 2
    Pin 26: LED 3
    Pin 25: LED 4
    Pin 33: LED 5
    Pin 32: LED 6
  The program first chases LEDs in forward order, then reverses the 
  sequence to chase them backward, resulting in a continuous loop 
  of forward and backward chaser effects.

  Created: October 2024
  Organization: INVOOTECHNICA GLOBAL PVT. LTD.
*/

#define LED1  14
#define LED2  27
#define LED3  26
#define LED4  25
#define LED5  33
#define LED6  32

int LEDARRAY[] = { LED1, LED2, LED3, LED4, LED5, LED6 };
int arraySize = sizeof ( LEDARRAY ) / sizeof ( LEDARRAY[0] );

void setup ( ) {
  for ( int i = 0; i < 6; i++ ) {
    pinMode ( LEDARRAY[i], OUTPUT );  
  } 
}

void loop ( ) {
  for ( int i = 0; i < arraySize; i++ ) {
    digitalWrite ( LEDARRAY[i], HIGH );
    delay ( 150 );
    digitalWrite ( LEDARRAY[i], LOW );
  }
  for ( int i = arraySize - 1; i >= 0; i-- ) {
    digitalWrite ( LEDARRAY[i], HIGH );
    delay ( 150 );
    digitalWrite ( LEDARRAY[i], LOW );
  }
}
