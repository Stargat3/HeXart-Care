#include "coeur.h"
#include "param.h"
#include <Arduino.h>

#define DELAY 250

int listePIN[10]= {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void initialisationCool()
{
  for(int i=0; i<10;i++){
    pinMode(listePIN[i], OUTPUT);
  }
  for(int i=0; i<10;i++){
    digitalWrite(listePIN[i], HIGH);
    delay(100);
  }
  for(int i=9; i>=0; i--){
    digitalWrite(listePIN[i], LOW);
    delay(100);
  }
}

void changerLED()
{
  //int mode;
  //int nbrLED;
   if(mode==1){
    for(int i=0;i<10;i++){
      digitalWrite(listePIN[i], HIGH);
    }
    delay(DELAY);
    for(int i=0;i<10;i++){
      digitalWrite(listePIN[i], LOW);
    }
   }
   else if(mode == 2){
    for(int i=0;i<10;i+=2){
      digitalWrite(listePIN[i], HIGH);
    }
    delay(DELAY);
    for(int i=0;i<10;i+=2){
      digitalWrite(listePIN[i], LOW);
    }
   }
   else if(mode == 3){
     for(int i=0;i<10;i+=3){
       digitalWrite(listePIN[i], HIGH);
     }
     delay(DELAY);
     for(int i=0;i<10;i+=3){
       digitalWrite(listePIN[i], LOW);
     }
   }
   else if(mode == 4){
     static int LED_ON = 0;
     digitalWrite(listePIN[LED_ON], LOW);
     LED_ON++;
     if(LED_ON>=10){
      LED_ON-=10;
     }
     digitalWrite(listePIN[LED_ON], HIGH);
   }
   else if(mode == 5){
    digitalWrite(listePIN[nbrLED], HIGH);
    delay(DELAY);
    digitalWrite(listePIN[nbrLED], LOW);
   }
}
