/*
  Seven Segment Display Down-Counter Program (Common Anode)
  This program decrements a counter from 9 to 0 and displays the 
  corresponding digit on a common anode 7-segment display. The 
  display is connected to the ESP32 microcontroller.

  Segment to pin mapping:
    A  - Pin 26
    B  - Pin 25
    C  - Pin 13
    D  - Pin 32
    E  - Pin 33
    F  - Pin 27
    G  - Pin 14
    DP - Pin 15 (not used in this program)
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
#define COM    19

// Segment mapping for digits 0-9 (Common Anode)
// Order: {A, B, C, D, E, F, G}
const int digitMap[10][7] = {
  { 0, 0, 0, 0, 0, 0, 1 }, // 0
  { 1, 0, 0, 1, 1, 1, 1 }, // 1
  { 0, 0, 1, 0, 0, 1, 0 }, // 2
  { 0, 0, 0, 0, 1, 1, 0 }, // 3
  { 1, 0, 0, 1, 1, 0, 0 }, // 4
  { 0, 1, 0, 0, 1, 0, 0 }, // 5
  { 0, 1, 0, 0, 0, 0, 0 }, // 6
  { 0, 0, 0, 1, 1, 1, 1 }, // 7
  { 0, 0, 0, 0, 0, 0, 0 }, // 8
  { 0, 0, 0, 0, 1, 0, 0 }  // 9
};

int SEGMENTS[] = { SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G };

void setup ( ) {
  // Set all segment pins as OUTPUT
  for ( int i = 0; i < 7; i++ ) {
    pinMode ( SEGMENTS[i], OUTPUT );
  }
  // Set COM pin as OUTPUT and set to HIGH to enable the SSD
  pinMode ( COM, OUTPUT );
  digitalWrite ( COM, HIGH ); // Enable common anode by connecting it to VCC
}

void loop ( ) {
  for ( int digit = 9; digit >= 0; digit-- ) { // Count down from 9 to 0
    displayDigit ( digit );
    delay ( 1000 ); // Delay 1 second between each digit
  }
}

// Function to display a digit on the 7-segment display
void displayDigit ( int digit ) {
  for ( int i = 0; i < 7; i++ ) {
    digitalWrite ( SEGMENTS[i], digitMap[digit][i] );
  }
}
