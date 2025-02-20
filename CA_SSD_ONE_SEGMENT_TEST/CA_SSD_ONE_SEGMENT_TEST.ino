/*
  Seven Segment Display Test Program (Common Anode)
  This program sequentially turns on each segment (A, B, C, D, E, F, G, and DP)
  of a common anode 7-segment display for testing purposes. The COM pin 
  of the display is connected to VCC via pin 19.

  Segment to pin mapping:
    A  - Pin 26
    B  - Pin 25
    C  - Pin 13
    D  - Pin 32
    E  - Pin 33
    F  - Pin 27
    G  - Pin 14
    DP - Pin 15
  Common Anode (COM) - Pin 19

  Created: November 2024
  Organization: INVOOTECHNICA GLOBAL PVT. LTD.
*/

#define SEG_A  26
#define SEG_B  25
#define SEG_C  13
#define SEG_D  32
#define SEG_E  33
#define SEG_F  27
#define SEG_G  14
#define SEG_DP 15
#define COM    19

int SEGMENTS[] = { SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP };

void setup ( ) {
  // Set all segment pins as OUTPUT
  for ( int i = 0; i < 8; i++ ) {
    pinMode ( SEGMENTS[i], OUTPUT );
  }
  // Set COM pin as OUTPUT and set to HIGH to enable the SSD
  pinMode ( COM, OUTPUT );
  digitalWrite ( COM, HIGH ); // Enable common anode by connecting it to VCC
}

void loop ( ) {
  for ( int i = 0; i < 8; i++ ) {
    digitalWrite ( SEGMENTS[i], LOW );  // Turn on the current segment
    delay ( 500 );                      // Wait 500 milliseconds
    digitalWrite ( SEGMENTS[i], HIGH ); // Turn off the current segment
  }
}
