#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"

struct editor{
    char* nome;
};

char* retornaNomeEditor (Editor* editor){
    return (editor -> nome);
}

void imprimeEditor (Editor* editor){
    printf("%s\n", retornaNomeEditor (editor));
}

void destroiEditor (Editor* editor){
    free(editor -> nome);
    free(editor);
}

Editor* criaEditor (char nome[20]){
    Editor* editor = (Editor*) malloc (sizeof(Editor));
    editor -> nome = strdup(nome);
}
