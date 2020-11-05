/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCont.c
 * Author: joao
 * 
 * Created on 29 de Outubro de 2020, 19:58
 */

#include "Contribuicao.h"
#include "ListaCont.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula{
    Contribuicao* cont;
    Celula* prox;
};

struct lista_cont{
    Celula* prim;
    Celula* ult;
};

ListaCont* iniciaListaCont(){
    ListaCont* lista;
    lista = (ListaCont*) malloc (sizeof(ListaCont));
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

Contribuicao* retornaContribuicao(ListaCont* lista, char chave[20]){
    Celula* cel;
    
    for(cel=lista -> prim; cel !=NULL; cel = cel-> prox){
        if (!strcmp(chave, retornaNomeContribuicao (cel -> cont))){
            return cel-> cont;
        }
    }
    return (NULL);
}

void insereListaCont (ListaCont* lista, Contribuicao* cont){
    Celula* celula;
    celula = (Celula*) malloc (sizeof(Celula));
    celula -> cont = cont;
    if (lista -> ult != NULL) lista -> ult -> prox = celula;
    lista -> ult = celula;
    celula -> prox = NULL;
    
    if(lista -> prim == NULL) lista -> prim = celula;
}

void imprimeListaCont (ListaCont* lista, char* nome){   
    
    Celula* aux_cell;
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        imprimeContribuicao (aux_cell -> cont, nome);
    }
}

void imprimeListaContNomes (ListaCont* lista, char* nome){
    
    Celula* aux_cell;
    
    FILE* file;
    
    file = fopen (nome, "a");
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        fprintf(file,"%s %s", retornaNomeEditorCont(aux_cell -> cont), retornaNomeContribuicao (aux_cell -> cont));
        if (retornaRemovida(aux_cell -> cont)){
            fprintf(file," <<retirada>>\n");
        }
        else{
            fprintf(file,"\n");
        }
    }
    fclose(file);
}

void retiraListaCont(ListaCont* lista, char chave[20]){
    Celula* celula = lista -> prim;
    Contribuicao* cont;
    Celula* anterior = NULL;
    
    
    while (celula != NULL && strcmp(retornaNomeContribuicao(celula -> cont), chave)){
        anterior = celula;
        celula = celula -> prox;
    }
    
    if (celula == NULL){
        return;
    }
    
    cont = celula -> cont;
    
    if (celula == lista -> prim && celula == lista -> ult){
        lista -> prim = lista -> ult = NULL;
    }
    else if (celula == lista -> prim){
        lista -> prim = celula -> prox;
    }
    else if (celula == lista -> ult){
        lista -> ult = anterior;
        lista -> ult -> prox =NULL;
    }
    else{
        anterior -> prox = celula -> prox;
    }
    
    destroiContribuicao (celula -> cont);
    free(celula);
}

void removeListaCont(ListaCont* lista, char chave[20]){
    Celula* celula;
    Contribuicao* cont;
    
    
    for(celula = lista -> prim; celula != NULL; celula = celula -> prox){
        if(!strcmp(retornaNomeContribuicao(celula -> cont), chave)){
            removeContribuicao (celula -> cont);
        }
    }
}

void destroiListaCont (ListaCont* lista){
    Celula* celula;
    Celula* aux_cel;
    
    celula = lista -> prim;
    
    while (celula !=NULL){
        aux_cel = celula -> prox;
        destroiContribuicao (celula -> cont);
        free(celula);
        celula = aux_cel;
    }
    
    free(lista);
}
