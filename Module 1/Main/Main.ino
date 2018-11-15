extern "C" {
#include "cardio.h"
}

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
/* Initialise le générateur de nombre aléatoire avec une graine aléatoire */
}

void loop()
{ 
  char *text;
  text = malloc(300*sizeof(char));
  simulationPulsation(&text);
  Serial.println(text);
  Serial.write(text);
  delay(500);
}
