/*  Glen Larsen "scanner" effect
 *  Based on a number of sources on the internet, none
 *  of which provided the exact function I was looking 
 *  for.
 *
 *  It is broken and needs a little work. Perhaps using the
 *  interrupt button to toggle states?
 *
 *  Supposedly I should be avoiding delay and using millis.
 *  The real solution would be to go through some tutorials 
 *  so I know what I'm doing. I suspect I'm conceptualizing
 *  this incorrectly.
 *
 *  2018-11-18
 *  Scott Murphy
 */
 
const int buttonPin = 2;
int cState = HIGH;
int pState = HIGH;
int enabled = 0;

int leds[] = {6, 7, 8, 9, 10, 11, 12, 13};
#define NUMBER_OF_LEDS (sizeof(leds)/sizeof(int))

boolean larson[][NUMBER_OF_LEDS] = {
{ HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW},
{ HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  LOW},
{ HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW},
{ LOW,  HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW},
{ LOW,  LOW,  HIGH, HIGH, HIGH, LOW,  LOW,  LOW},
{ LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, LOW,  LOW},
{ LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, LOW},
{ LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, HIGH},
{ LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH},
{ LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH},
{ LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH},
{ LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, HIGH},
{ LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, LOW},
{ LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, LOW,  LOW},
{ LOW,  LOW,  HIGH, HIGH, HIGH, LOW,  LOW,  LOW},
{ LOW,  HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW},
{ HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW},
{ HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  LOW},
{ HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW},
{ LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW},
};

#define FRAMES (sizeof(larson)/(sizeof(larson[0])))

void setup() {
  pinMode(buttonPin, INPUT);
  for (int led=0; led<NUMBER_OF_LEDS; led++) {
    pinMode(leds[led], OUTPUT);
  }
}

void loop(){
  cState = digitalRead(buttonPin);
  if (cState != pState) {
    if ((cState == LOW) && (enabled == 1)){
      enabled = 0;
    } else {
      enabled = 1;
    }
  }
  delay(100);
  pState = cState;
  if (enabled == 1){
    for (int frame=0; frame<FRAMES; frame++) {
      for (int led=0; led<NUMBER_OF_LEDS; led++) {
        digitalWrite(leds[led], larson[frame][led]);
      }
      delay(100);
    }
  }
}
