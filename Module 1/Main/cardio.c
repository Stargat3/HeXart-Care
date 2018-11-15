#include "cardio.h"
//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <Arduino.h>


//void detecter()
unsigned long time;

void simulationPulsation(char **p1)
{
  char *info;
  info = *p1;
  // Génére un nombre aléatoire entre 0 et 255
  long nombre = (random()%21)+70;
  time = millis();
  char buffer[30];
  sprintf(buffer, "%ld", nombre);
  //char info[300] = "";
  info[0] = "";
  //strcpy(info, "");
  strcat(info, buffer);
  strcat(info, ";");
  buffer[0] = "";
  sprintf(buffer, "%ld", time);
  strcat(info, buffer);
  strcat(info, " \0");
  //return info;
  //Serial.write(info);
  //delay(500);
}
