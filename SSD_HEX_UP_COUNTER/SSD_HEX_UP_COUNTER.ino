/*
  Seven Segment Display Hexadecimal Up-Counter Program
  This program increments a counter from 0 to F (hexadecimal) 
  and displays the corresponding digit or letter on a common 
  cathode 7-segment display. The display is connected to the ESP32 
  microcontroller.

  Segment to pin mapping:
    A  - Pin 26
    B  - Pin 25
    C  - Pin 13
    D  - Pin 32
    E  - Pin 33
    F  - Pin 27
    G  - Pin 14
    DP - Pin 15 (not used in this program)
  Common Cathode (COM) - Pin 19

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
#define COM    19

// Segment mapping for hexadecimal digits 0-F (Common Cathode)
// Order: {A, B, C, D, E, F, G}
const int hexMap[16][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 }, // 9
  { 1, 1, 1, 0, 1, 1, 1 }, // A
  { 0, 0, 1, 1, 1, 1, 1 }, // B
  { 1, 0, 0, 1, 1, 1, 0 }, // C
  { 0, 1, 1, 1, 1, 0, 1 }, // D
  { 1, 0, 0, 1, 1, 1, 1 }, // E
  { 1, 0, 0, 0, 1, 1, 1 }  // F
};

int SEGMENTS[] = { SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G };

void setup ( ) {
  // Set all segment pins as OUTPUT
  for ( int i = 0; i < 7; i++ ) {
    pinMode ( SEGMENTS[i], OUTPUT );
  }
  // Set COM pin as OUTPUT and set to LOW to enable the SSD
  pinMode ( COM, OUTPUT );
  digitalWrite ( COM, LOW ); // Enable common cathode by connecting it to GND
}

void loop ( ) {
  for ( int digit = 0; digit < 16; digit++ ) { // Count from 0 to F (hexadecimal)
    displayHexDigit ( digit );
    delay ( 1000 ); // Delay 1 second between each digit
  }
}

// Function to display a hexadecimal digit on the 7-segment display
void displayHexDigit ( int digit ) {
  for ( int i = 0; i < 7; i++ ) {
    digitalWrite ( SEGMENTS[i], hexMap[digit][i] );
  }
}
