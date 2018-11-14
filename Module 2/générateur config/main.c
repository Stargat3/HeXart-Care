#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int main()
{
    int mode, nbrLED=0;
    //mode fais appel au prototype menu()//
    mode = menu();
    //si le mode 5 a était choisi alors on demande a l'utilisateur de définir le nbr de LED.//
    if (mode==5)
    //fais appel au prototype choixLED()//
        nbrLED = choixLED();
    //création du param.h avec le mode ainsi que le nbr de LED//
    createParam(mode, nbrLED);
    return 0;
}
