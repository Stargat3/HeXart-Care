#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

#define NOMBRE_MESURE_MAX 1250

int main()
{
    struct infos *list;
    list = (struct infos*)malloc(sizeof(struct infos) * (NOMBRE_MESURE_MAX));
    FILE* fichier = ouvrirFichier();
    int tailleDonnee = 0;
    initialisation(&list, &tailleDonnee, fichier);
    menu(&list, &tailleDonnee);
    /*
    struct infos infostab[5];
    initialisation(&infostab, &tailleDonnee);
    menu(&infostab);
    */
    return (0);
}
