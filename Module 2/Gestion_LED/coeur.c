#include "coeur.h"
#include "param.h"
#include <Arduino.h>/*on inclut la librairie Arduin.h dans le programme*/

//on prédéfini le temps du delay pour éviter d'écrire a chaque fois la valeur//
#define DELAY 250
//liste des differentes LED que nous utilisons//
int listePIN[10]={2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void initialisationCool()
{
  //Permet de initialiser tout les LEDS comme étants des sorties ou le courant peut passer//
  for(int i=0; i<10;i++){
    pinMode(listePIN[i], OUTPUT);
  }
  //permet d'allumer les LEDS en série en les laissant allumer//
  for(int i=0; i<10;i++){
    digitalWrite(listePIN[i], HIGH);
    delay(100);
  }
  //permet d'éteindre les LEDS en série( a l'inverse de l'allumage)//
  for(int i=9; i>=0; i--){
    digitalWrite(listePIN[i], LOW);
    delay(100);
  }
  
}

void changerLED()
{
  //le mode 1 correspond a toute les LEDS qui clignote en même temps//
   if(mode==1){
    for(int i=0;i<10;i++){
      digitalWrite(listePIN[i], HIGH);//Cette ligne permet de dire la a LED[i] de s'allumer//
    }
    //on inclut un delay pour laisser le temps de voir le clignotement//
    delay(DELAY);
    for(int i=0;i<10;i++){
      digitalWrite(listePIN[i], LOW);//Cette ligne permet d'éteindre les LEDS// 
    }
   }
   //le mode 2 permet d'allumer une LED sur deux//
   else if(mode == 2){
    for(int i=0;i<10;i+=2){
      digitalWrite(listePIN[i], HIGH);
    }
    delay(DELAY);
    for(int i=0;i<10;i+=2){
      digitalWrite(listePIN[i], LOW);
    }
   }
   //Il permet de faire clignoter une LED sur 3//
   else if(mode == 3){
     for(int i=0;i<10;i+=3){
       digitalWrite(listePIN[i], HIGH);
     }
     delay(DELAY);
     for(int i=0;i<10;i+=3){
       digitalWrite(listePIN[i], LOW);
     }
   }
   //Il permet de faire clignote les LEDS en chaines//
   else if(mode == 4){
     static int LED_ON = 9;//static permet de sauvegarder la variable, elle ne sera pas surprimé par la fin de la fonction//.
     digitalWrite(listePIN[LED_ON], LOW);
     LED_ON++;
     if(LED_ON>=10){
      LED_ON-=10;
     }
     digitalWrite(listePIN[LED_ON], HIGH);
   }
   //Il permet de faire clignoter un LED au choix//
   else if(mode == 5){
    digitalWrite(listePIN[nbrLED-1], HIGH);
    delay(DELAY);
    digitalWrite(listePIN[nbrLED-1], LOW);
   }
   //Il permet de faire clignoter en chaine(c'est le mode bonus)//
   else if(mode == 6){
    static int etat = 0;
    if(etat>=0 && etat<=9){
      digitalWrite(listePIN[etat], HIGH);
    }
    else if(etat>=10 && etat<=19){
      digitalWrite(listePIN[etat-10], LOW);
    }
    etat++;
    if(etat==20){
      etat = etat - 20;
    }
   }
   //Il permet de faire clignoter les LEDS de manière aléatoire//
   else if(mode == 7){
    static byte etatPIN[10] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
    int editLED = random()%10;
    //Les deux prchaine lignes permettes de si une LED est déja allumé est quelle se rallume alors elle s'éteind, elle inverse sa focntion//$
    etatPIN[editLED] = !etatPIN[editLED];
    digitalWrite(listePIN[editLED], etatPIN[editLED]);
   }
}
