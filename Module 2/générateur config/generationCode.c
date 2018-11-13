#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

void createParam(int mode, int nbrLED){
    FILE* param_h;//c'est la route pour aller au fichier//
    param_h = createFile();
    fprintf(param_h, "#ifndef PARAM_H_INCLUDE\n");
    fprintf(param_h, "#define PARAM_H_INCLUDE\n");
    fprintf(param_h, "const extern int mode=%d;\n", mode);//extern est une variable accessible a tout le monde//
    fprintf(param_h, "const extern int nbrLED=%d;\n",nbrLED);
    fprintf(param_h, "#endif");
}

FILE* createFile(){
    FILE* fichier;
    fichier = fopen("param.h", "w");
    return fichier;
}
