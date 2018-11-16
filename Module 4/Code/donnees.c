#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

FILE* ouvrirFichier()
{
    FILE* fichier = NULL;
    fichier = fopen("Battements.csv", "r");
    fscanf(fichier, "%*[^\n]\n");
    return fichier;
}

void initialisation (struct infos **p_infos, int *n, FILE* fichier)
{
    if (fichier != NULL) // Si le fichier existe alors éxecute le programme(on écrit dans le fichier)//
    {
        struct infos *temp;
        temp = *p_infos;
        int i = 1;
        while(i)
        {
            fscanf(fichier, "%d%*c%ld ", &(temp[*n].pouls), &(temp[*n].temps));
            (*n)++;
            if((temp[(*n)-1].pouls) <= 0 && (temp[(*n)-1].temps) <= 0)
            {
                i = 0;
                (*n)--;
            }
        }
    }
    //si le fichiers n'éxiste pas alors on affiche://
    else
    {
        printf("Impossible d'ouvrir le fichier test.csv\n\n");
    }
    //on referme le fichier//
    fclose(fichier);
}
