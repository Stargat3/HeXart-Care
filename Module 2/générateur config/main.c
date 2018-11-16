#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int main()
{
    int mode = -1, nbrLED=0;
    //mode fais appel au prototype menu()//
	while(!(mode>0 && mode<6))
	{
		mode = menu();
		//si le mode 5 a était choisi alors on demande a l'utilisateur de définir le nbr de LED.//
		if (mode==5)
		//demande à l'utilisateur de choisir une LED//
			while(!(nbrLED>=0 && nbrLED<=10))
			{
				nbrLED = choixLED();
			}
	}
	//création du param.h avec le mode ainsi que le nombre de LED//
    createParam(mode, nbrLED);
    return 0;
}
