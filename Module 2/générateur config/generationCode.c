#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

void createParam(int mode, int nbrLED){
    //c'est la route pour aller au fichier//
    FILE* param_h;
    param_h = createFile();
    fprintf(param_h, "#ifndef PARAM_H_INCLUDE\n");
    fprintf(param_h, "#define PARAM_H_INCLUDE\n");
    //extern est une variable accessible a tout le monde//
    fprintf(param_h, "const extern int mode=%d;\n", mode);
    fprintf(param_h, "const extern int nbrLED=%d;\n",nbrLED);
    fprintf(param_h, "#endif");
}

//ce block permet de crée un nv fichier,param.h ,La commande "w" permet d'écrire//
FILE* createFile(){
    FILE* fichier;
    fichier = fopen("param.h", "w");
    return fichier;
}
