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
    if (fichier != NULL) // Si le fichier existe
    {
        struct infos *temp;
        temp = *p_infos;
        int i = 1;
        while(i)
        {
            fscanf(fichier, "%d%*c%ld ", &(temp[*n].pouls), &(temp[*n].temps));
            printf("%d\n", *n);
            printf("%d;%ld\n", temp[*n].pouls, temp[*n].temps);
            (*n)++;
            if((temp[(*n)-1].pouls) <= 0 && (temp[(*n)-1].temps) <= 0)
            {
                i = 0;
                (*n)--;
            }
        }
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.csv\n\n");
    }
    fclose(fichier);
}
