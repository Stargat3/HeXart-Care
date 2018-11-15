#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

void affichage(struct infos **p_infos, int *n, int Ordre)
{
    struct infos *temp;
    temp = *p_infos;
    for (int i=0; i<(*n); i++)
    {
        printf("Pouls : %d Temps : %ld\n", temp[i].pouls, temp[i].temps);
    }
}

void rechercheMinMax(struct infos **p_infos, int *n)
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

void affichagemoyenne(struct infos **p_infos, int* n)
{
    float resultat = 0.0;
    struct infos *temp;
    temp = *p_infos;

    for (int i=0; i<(*n);i++)
    {
        resultat += temp[i].pouls;
    }
    resultat = resultat / (*n);
    printf("La moyenne du pouls est %f\n", resultat);
}

void affichagenbrlignes(int* n)
{
    printf("Il y a %d valeurs de pouls en mémoire.\n", *n);
}

void triListePouls(struct infos **p_infos, int* n)
{
    struct infos *temp;
    temp = *p_infos;
    int permut = 1;
    int passage = 0;
    int tempPouls;
    long tempTemps;
    while(permut)
    {
        permut = 0;
        passage++;
        for(int i=0; i<(*n)-passage; i++)
        {
            if(temp[i].pouls > temp[i+1].pouls)
            {
                permut = 1;
                tempPouls = temp[i].pouls;
                tempTemps = temp[i].temps;
                temp[i].pouls = temp[i+1].pouls;
                temp[i].temps = temp[i+1].temps;
                temp[i+1].pouls = tempPouls;
                temp[i+1].temps = tempTemps;
            }
        }
    }
}

void triListeTemps(struct infos **p_infos, int* n)
{
    struct infos *temp;
    temp = *p_infos;
    int permut = 1;
    int passage = 0;
    int tempPouls;
    long tempTemps;
    while(permut)
    {
        permut = 0;
        passage++;
        for(int i=0; i<(*n)-passage; i++)
        {
            if(temp[i].temps > temp[i+1].temps)
            {
                permut = 1;
                tempPouls = temp[i].pouls;
                tempTemps = temp[i].temps;
                temp[i].pouls = temp[i+1].pouls;
                temp[i].temps = temp[i+1].temps;
                temp[i+1].pouls = tempPouls;
                temp[i+1].temps = tempTemps;
            }
        }
    }
}

void recherche(struct infos **p_infos,int *n, int value)
{
    triListeTemps(p_infos, n);
    struct infos *temp;
    temp = *p_infos;
    int indice = -1;
    for(int i = 0; i<(*n); i++)
    {
        if(temp[i].temps > value)
        {
            indice = i;
            break;
        }
    }
    if(indice == 0 || indice == -1)
    {
        printf("Le pouls correspondant au temps le plus est %d (%ld millisecondes).\n", temp[indice].pouls, temp[indice].temps);
    }
    else if(indice > 0 && indice <= (*n)-1 )
    {
        printf("Le pouls precedant le plus proche est %d (%ld millisecondes).\n", temp[indice-1].pouls, temp[indice-1].temps);
        printf("Le pouls suivant le plus proche est %d (%ld millisecondes).\n", temp[indice].pouls, temp[indice].temps);
    }
}
