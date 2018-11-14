#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int menu()
{
    int mode;
    int c;
    printf("----Bonjour----\n Quel mode voulez-vous?\n 1-Coeur qui bat à chaque pulsation\n 2-Allumage de 1 LED sur 2\n 3-Allumage de 1 LED sur 3\n 4-Mode chenille\n 5-LED qui clignote au choix\n 0-quitter\n");
    scanf("%d",&mode);
    //Permet d'effacer la memoire temporaire du scanf() et d'eviter les bugs (caractere incompatible)//
    while ((c = getchar()) != '\n' && c != EOF) { }
    //si le mode est superieur a 0 et inferieur a 6 alors le param.h est crée avec le mode choisi//
    if(mode>0 && mode<6){
        return mode;
    }
    return -1;
}

int choixLED(){
    int nbrLED;
    printf("Quelle LED veux tu allumer ?\n");
    scanf("%d",&nbrLED);
    return nbrLED;
}
