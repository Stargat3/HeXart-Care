#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

void affichage(struct infos *p_infos)
{
    for (int i=0; i<5; i++)
    {
        printf("%d\n%d\n", p_infos->pouls, p_infos->temps);
        p_infos=p_infos+1;
    }
}

void rechercheminmax(struct infos *p_infos)
{
    int i,max,min;
    int origine=p_infos;

    // Calcul du pouls maximum

    max=p_infos->pouls;

printf("\nle maximum pouls du tableau est : ");
for (i=0; i<5; i++)
{
if(p_infos->pouls>max)
{
    max=p_infos->pouls;
}
p_infos=p_infos+1;

}
printf("%d avec un temps de %d\n\n",max, p_infos->temps);

  //Calcul du minimum pouls du tableau

p_infos=origine;
min=p_infos->pouls;

printf("\nle minimum pouls du tableau est : ");
for (i=0; i<5; i++)
{
if(p_infos->pouls<min)
min=p_infos->pouls;
}
printf("%d avec un temps de %d\n\n",min, p_infos->temps);

}

