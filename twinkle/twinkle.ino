#include "pitches.h"
 
// notes in the melody:
// int melody[] = {
//  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_GS3, NOTE_G3,0, NOTE_B3, NOTE_C4};
// 
// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] = {
//  4, 8, 8, 4,4,4,4,4 };

// ABD notation
// X: 2
// T: Twinkle Little Star
// R: reel
// M: 4/4
// L: 1/8
// K: Cmaj
// C2C2G2G2|A2A2G4|F2F2E2E2|D2D2C4|
// G2G2F2F2|E2E2D4|G2G2F2F2|E2E2D4|
// C2C2G2G2|A2A2G4|F2F2E2E2|D2D2C4:|
//
// trying a new one

int melody[] = {
  NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,
  NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4
};

int noteDurations[] = {
  4,4,4,4,4,4,2,4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,4,4,4,4,4,4,2
};

// Does arduino 'C' understand sizeof()?
// Yes, but it returns the length of the entire array in bytes
// We need to divide by the size of an element
 
void setup() {
  // iterate over the notes of the melody:
  int arraySize = sizeof(noteDurations) / sizeof(noteDurations[0]);
  for (int thisNote = 0; thisNote < arraySize; thisNote++) {
 
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(A3, melody[thisNote],noteDuration);
 
    //pause for the note's duration plus 30 ms:
    delay(noteDuration +30);
  }
}
 
void loop() {
  // no need to repeat the melody.
}
