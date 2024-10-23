/*
  LED Center-to-End Chaser Program
  This program turns on and off LEDs connected to digital pins 
  14, 27, 26, 25, 33, and 32 of an ESP32 microcontroller. The LEDs 
  glow outward starting from the center (LED 3 on pin 26 and LED 4 on pin 25) 
  and move symmetrically to the ends. Each pair of LEDs lights up 
  for 150 milliseconds before turning off, creating a chaser effect 
  from the center to the outermost LEDs. (Even number of LED)
  Pin assignments:
    Pin 14: LED 1 (end)
    Pin 27: LED 2
    Pin 26: LED 3 (center)
    Pin 25: LED 4 (center)
    Pin 33: LED 5
    Pin 32: LED 6 (end)
  Created: October 2024
  Org: INVOOTECHNICA GLOBAL PVT. LTD.                            */

#define LED1  14
#define LED2  27
#define LED3  26
#define LED4  25
#define LED5  33
#define LED6  32

int LEDARRAY[] = { LED1, LED2, LED3, LED4, LED5, LED6 };
int arraySize = sizeof ( LEDARRAY ) / sizeof ( LEDARRAY[0] );
int mid = ( arraySize / 2 ) - 1;

void setup ( ) {
  for ( int i = 0; i < 6; i++ ) {
    pinMode ( LEDARRAY[i], OUTPUT );  
  } 
}

void loop ( ) {
  for ( int i = 0; i <= mid; i++ ) {
    digitalWrite ( LEDARRAY[mid + i + 1], HIGH );
    digitalWrite ( LEDARRAY[mid - i], HIGH );
    delay ( 150 );
    digitalWrite ( LEDARRAY[mid + i + 1], LOW );
    digitalWrite ( LEDARRAY[mid - i], LOW );
  }   
}
