#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"

//Il pemet d'afficher le pouls en fonction du temps par rapport au information qu'il y a dans le double pointeur **p_infos//
void affichage(struct infos **p_infos, int *n, int Ordre)
{
    /*on crée un pointeur simple a partir de notre double pointeurs pour faciliter sont utilisation, le simple pointeur on peut y accèder comme un tableau*/
    struct infos *temp;
    temp = *p_infos;

    for (int i=0; i<(*n); i++)
    {
        printf("Pouls : %d Temps : %ld\n", temp[i].pouls, temp[i].temps);
    }
}
//Il permet de faire une recherche de maximun et de minimun//
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

//Il permet d'afficher la moyenne//
void affichageMoyenne(struct infos **p_infos, int* n)
{
    float resultat = 0.0;
     /*on crée un pointeur simple a partir de notre double pointeurs pour faciliter son utilisation,on peut y accèder comme un tableau*/
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
//tri de la liste en fonction du pouls//
void triListePouls(struct infos **p_infos, int* n)
{
    struct infos *temp;
     /*on crée un pointeur simple a partir de notre double pointeurs pour faciliter sont utilisation,on peut y accèder comme un tableau*/
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
//tri de la liste en fonction du temps//
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
//recherche d'une valeur de pouls a partir d'un temps//
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
