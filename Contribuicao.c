/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contribuicao.c
 * Author: joao
 * 
 * Created on 25 de Outubro de 2020, 12:27
 */

#include "Contribuicao.h"
#include "Editor.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct contribuicao{
    char* texto;
    char* nome;
    Editor* autor;
    int removida;
};


Contribuicao* iniciaContribuicao (char nome[20], Editor* editor){
    
    FILE * file;
    
    file = fopen (nome, "r");
    if(file == NULL){
        file = fopen ("log.txt", "r+");
        fprintf(file, "A contribuicao %s nao existe\n", nome);
        fclose(file);
        return (NULL);
    }
    
    fclose(file);
    
    Contribuicao* cont = (Contribuicao*) malloc (sizeof(Contribuicao));
    cont -> nome = strdup(nome);
    cont -> removida = 0;
    cont -> autor = editor;
    
    long numbytes;

    file = fopen(nome, "r");

    fseek(file, 0L, SEEK_END);
    numbytes = ftell(file);

    fseek(file, 0L, SEEK_SET);	

    cont -> texto = (char*)calloc((numbytes + 1), sizeof(char));	

    if(cont -> texto == NULL){
        file = fopen ("log.txt", "r+");
        fprintf(file, "Nao foi possivel alocar buffer\n");
        fclose(file);
        return (NULL);
    }

    fread(cont -> texto, sizeof(char), (numbytes + 1), file);
    fclose(file);
    
    return (cont);
}

char* retornaNomeContribuicao (Contribuicao* cont){
    return (cont -> nome);
}

Editor* retornaAutorContribuicao (Contribuicao* cont){
    return (cont -> autor);
}

void removeContribuicao (Contribuicao* cont){
    cont -> removida = 1;
}

void destroiContribuicao (Contribuicao* cont){
    free (cont -> nome);
    free (cont -> texto);
    free (cont);
}

void imprimeContribuicao (Contribuicao* cont, char* nome){
    
    if (cont -> removida) return;
    
    FILE * file;
    
    file = fopen (nome, "a");
    
    fprintf(file, "-------- %s (%s) --------\n\n", retornaNomeContribuicao(cont), 
                                               retornaNomeEditor (retornaAutorContribuicao (cont)));
    
    fprintf(file, "%s\n\n", cont -> texto);
    fclose(file);
    
}

char* retornaNomeEditorCont(Contribuicao* cont){
    char* nome = retornaNomeEditor (cont -> autor);
    return nome;
}