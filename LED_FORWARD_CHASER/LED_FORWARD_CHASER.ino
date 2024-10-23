/*
  LED Forward Chaser Program
  This program sequentially turns on and off LEDs connected to 
  digital pins 14, 27, 26, 25, 33, and 32 of an ESP32 microcontroller.
  Each LED turns on for 150 milliseconds, then turns off before 
  the next LED in the sequence is turned on.
  Pin assignments:
    Pin 14: LED 1
    Pin 27: LED 2
    Pin 26: LED 3
    Pin 25: LED 4
    Pin 33: LED 5
    Pin 32: LED 6
  The LEDs create a chaser effect, where each LED lights up 
  in sequence, creating a smooth running pattern.
  Created: October 2024
  Org: INVOOTECHNICA GLOBAL PVT. LTD.                            */

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
  for ( int i = 0; i < 6; i++ ) {
    digitalWrite ( LEDARRAY[i], HIGH );
    delay ( 150 );
    digitalWrite ( LEDARRAY[i], LOW );
  }   
}
