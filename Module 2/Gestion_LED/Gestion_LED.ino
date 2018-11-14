extern "C" {
#include "coeur.h"
}

void setup() {
  initialisationCool();
  randomSeed(analogRead(5));
  Serial.begin(9600);
}

void loop() {
  changerLED();
  delay(500);
}
