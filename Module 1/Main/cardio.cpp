#include "cardio.h"
#include <string.h>
#include <Arduino.h>

unsigned long time;

void initialisation()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void simulerPulsation()
{
  // Génére un nombre aléatoire entre 70 et 90 et l'affiche sur le port série 
  long nombre = (random()%21)+70;
  time = millis();
  char buffer[30];
  sprintf(buffer, "%ld", nombre);
  char info[300] = "";
  strcat(info, buffer);
  strcat(info, ";");
  sprintf(buffer, "%ld", time);
  strcat(info, buffer);
  strcat(info, " ");
  Serial.write(info);
  delay(500);
}
