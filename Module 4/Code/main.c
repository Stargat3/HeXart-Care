#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

#define NOMBRE_MESURE_MAX 2000

int main()
{
    struct infos *list;
    list = (struct infos*)malloc(sizeof(struct infos) * (NOMBRE_MESURE_MAX));
    FILE* fichier = ouvrirFichier();
    int tailleDonnee = 0;
    initialisation(&list, &tailleDonnee, fichier);
    menu(&list, &tailleDonnee);
    return (0);
}
