#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int main()
{
    int mode, nbrLED;
    mode = menu();
    if (mode==5)
        nbrLED = choixLED();
    createParam(mode, nbrLED);
    return 0;
}
