

#include "cardio.h"
//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <Arduino.h>


//void detecter()
unsigned long time;

void mesure()
{

  // Génére un nombre aléatoire entre 0 et 255 et l'affiche sur le port série 
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
//void calculer()


void initialisation()
{
  Serial.begin(9600);
}
