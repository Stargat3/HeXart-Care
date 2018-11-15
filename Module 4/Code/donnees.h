struct infos {
    int pouls;
    long temps;
};

//typedef struct infos infos;

void initialisation (struct infos **p_infos, int* n, FILE* fichier);
FILE* ouvrirFichier();
