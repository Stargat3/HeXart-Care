#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"



int main()
{
    infos infostab[5];
    initialisation(&infostab);
    menu(&infostab);
    return (0);
}
