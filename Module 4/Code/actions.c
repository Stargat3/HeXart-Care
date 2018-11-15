#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

void affichage(struct infos **p_infos, int *n)
{
    struct infos *temp;
    temp = *p_infos;
    for (int i=0; i<(*n); i++)
    {
        printf("Pouls : %d Temps : %ld\n", temp[i].pouls, temp[i].temps);
    }
}

void rechercheminmax(struct infos **p_infos, int *n)
{
    int i,max,min;
    struct infos *temp;
    temp = *p_infos;
    max=0;
    min=0;

    for (i=0; i<(*n); i++)
    {
        if(temp[i].pouls>temp[max].pouls)
        {
            max=i;
        }
        else if(temp[i].pouls<temp[min].pouls)
        {
            min=i;
        }
    }

printf("Le pouls maximum est %d bpm au temps de %ld milliseconde\n", temp[max].pouls, temp[max].temps);
printf("Le pouls minimum est %d bpm au temps de %ld millisecondes\n", temp[min].pouls, temp[min].temps);
}

