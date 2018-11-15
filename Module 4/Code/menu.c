#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"


void menu(struct infos **p_infos, int *n)
{
    struct infos *list;
    int Menu=0;
    int continuer = 1;
    do
    {
        printf("Chosir dans le menu\n");
        printf("1. Afficher les donnees dans l'ordre du fichier .csv\n");
        printf("2. Afficher les donnees en ordre croissant/décroissant (selon le temps, selon le pouls)\n");
        printf("3. Rechercher et afficher les donnees pour un temps particulier\n");
        printf("4. Afficher la moyenne de pouls dans une plage de temps donnee\n");
        printf("5. Afficher le nombre de lignes de données actuellement en mémoire\n");
        printf("6. Rechercher et afficher les max/min de pouls (avec le temps associe)\n");
        scanf("%d",&Menu);
        printf("\n");

        switch(Menu)
        {
        case 1 :
            affichage(p_infos, n);
            break;
        /*case 2 :
            affichagecroitdecroit();
            break;
        case 3 :
            recherche();
            break;
        case 4 :
            affichagemoyenne();
            break;
        case 5 :
            affichagenbrlignes();
            break;*/
        case 6 :
            rechercheminmax(p_infos);
            break;
        }
    printf("Continuer=1 ;Quitter=0 :\n");
    scanf("%d", &continuer);
    }
    while (continuer) ;

    system("PAUSE");

    // return 0;

}

