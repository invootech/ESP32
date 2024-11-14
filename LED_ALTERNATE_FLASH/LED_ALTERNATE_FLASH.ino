/*
  LED Alternate Flash Program
  This program alternately turns on and off LEDs connected to digital pins 
  14, 27, 26, 25, 33, and 32 of an ESP32 microcontroller. The LEDs 
  connected to odd-numbered pins (LED 1, LED 3, and LED 5) light up together, 
  while the LEDs connected to even-numbered pins (LED 2, LED 4, and LED 6) 
  are turned off. After 150 milliseconds, the pattern switches, turning off 
  the odd-numbered LEDs and turning on the even-numbered ones, creating 
  an alternate flashing effect.
  Pin assignments:
    Pin 14: LED 1
    Pin 27: LED 2
    Pin 26: LED 3
    Pin 25: LED 4
    Pin 33: LED 5
    Pin 32: LED 6
  The program alternates between turning on odd-numbered and 
  even-numbered LEDs, creating a flashing effect that continues 
  in a loop.

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

void setup ( ) {
  for ( int i = 0; i < 6; i++ ) {
    pinMode ( LEDARRAY[i], OUTPUT );  
  } 
}

void loop ( ) {
    digitalWrite ( LEDARRAY[1], HIGH );
    digitalWrite ( LEDARRAY[3], HIGH );
    digitalWrite ( LEDARRAY[5], HIGH );
    delay ( 150 );
    digitalWrite ( LEDARRAY[1], LOW );
    digitalWrite ( LEDARRAY[3], LOW );
    digitalWrite ( LEDARRAY[5], LOW );
  
    digitalWrite ( LEDARRAY[0], HIGH );
    digitalWrite ( LEDARRAY[2], HIGH );
    digitalWrite ( LEDARRAY[4], HIGH );
    delay ( 150 );
    digitalWrite ( LEDARRAY[0], LOW );
    digitalWrite ( LEDARRAY[2], LOW );
    digitalWrite ( LEDARRAY[4], LOW );
}
