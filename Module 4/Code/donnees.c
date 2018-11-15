#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

void initialisation (struct infos *p_infos)
{
    FILE* fichier=NULL;
    fichier = fopen("Battements.csv", "r");

    if (fichier != NULL) // Si le fichier existe
    {
          for(int i=0;i<5;i++)
            {
                fscanf(fichier,"%d %d",&p_infos->pouls, &p_infos->temps);
                p_infos=p_infos+1;
            }
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.csv\n\n");
        //return (1);
    }
    fclose(fichier);
}
