#include <stdio.h>
#include <stdlib.h>
//int�gration des diff�rentes biblioth�ques que nous avons cr��//
#include "donnees.h"
#include "actions.h"
#include "menu.h"


void menu(struct infos **p_infos, int *n)
{
    int Menu=0;
    int continuer = 1;
    int c;
    do
    {
        //menu//
        printf("Chosir dans le menu\n");
        printf("1. Afficher les donnees dans l'ordre du fichier .csv\n");
        printf("2. Afficher les donnees en ordre croissant/d�croissant (selon le temps, selon le pouls)\n");
        printf("3. Rechercher et afficher les donnees pour un temps particulier\n");
        printf("4. Afficher la moyenne de pouls dans une plage de temps donnee\n");
        printf("5. Afficher le nombre de lignes de donn�es actuellement en m�moire\n");
        printf("6. Rechercher et afficher les max/min de pouls (avec le temps associe)\n");
        scanf("%d",&Menu);
        //s�curit� pour emp�cher le programme de planter si l'utilisateur met de le scanf une lettre//
        while ((c = getchar()) != '\n' && c != EOF) { }

        switch(Menu)
        {
        case 1 :
            //
            triListeTemps(p_infos, n);
            affichage(p_infos, n, 1);
            break;
        case 2 :
            affichagecroitdecroit(p_infos, n);
            break;
        case 3 :
            printf("Merci de donner un temps en seconde :");
            int tempsVoulu;
            scanf("%d", &tempsVoulu);
            tempsVoulu *= 1000;
            recherche(p_infos, n, tempsVoulu);
            break;
        case 4 :
            affichagemoyenne(p_infos, n);
            break;
        case 5 :
            affichagenbrlignes(n);
            break;
        case 6 :
            rechercheMinMax(p_infos, n);
            break;
        }
    printf("Continuer=1 ;Quitter=0 :\n");
    scanf("%d", &continuer);

    while ((c = getchar()) != '\n' && c != EOF) { }

    }
    while (continuer) ;

    system("PAUSE");

}

void affichagecroitdecroit(struct infos **p_infos, int *n)
{
    int choixVar, Ordre;
    printf("Selon quelle valeur souhaitez vous affichez le tri ?\n");
    printf("1- Pouls\n");
    printf("2- Temps\n");
    scanf("%d", &choixVar);
    printf("Voulez-vous un affichage croissant ou decroissant ?\n");
    printf("1- Croissant\n");
    printf("2- Decroissant\n");
    scanf("%d", &Ordre);

    if(choixVar == 1 && (Ordre == 1 || Ordre == 2))
    {
        triListePouls(p_infos, n);
        affichage(p_infos, n, Ordre);
    }
    if(choixVar == 2 && (Ordre == 1 || Ordre == 2))
    {
        triListeTemps(p_infos, n);
        affichage(p_infos, n, Ordre);
    }
    else
    {
        printf("Une des 2 valeurs entr�es n'est pas bonne. Retour au menu.");
    }
}
