/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEditor.c
 * Author: joao
 * 
 * Created on 25 de Outubro de 2020, 11:07
 */

#include "ListaEditor.h"
#include "Editor.h"
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula{
    Editor* editor;
    Celula* prox;
};

struct lista_editor{
    Celula* prim;
    Celula* ult;
};

ListaEditor* iniciaListaEditor(){
    ListaEditor* lista;
    lista = (ListaEditor*) malloc (sizeof(ListaEditor));
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

void insereListaEditor (ListaEditor* lista, Editor* editor){
    Celula* celula;
    celula = (Celula*) malloc (sizeof(Celula));
    celula -> editor = editor;
    if (lista -> ult != NULL) lista -> ult -> prox = celula;
    lista -> ult = celula;
    celula -> prox = NULL;
    
    if(lista -> prim == NULL) lista -> prim = celula;
}

void imprimeListaEditor (ListaEditor* lista){
    Celula* celula;
    for (celula = lista -> prim; celula !=NULL; celula = celula -> prox){
        imprimeEditor(celula -> editor);
    }
}

void retiraListaEditor (ListaEditor* lista, char* chave){
    Celula* celula = lista -> prim;
    Editor* editor;
    Celula* anterior = NULL;
    
    
    while (celula != NULL && strcmp(retornaNomeEditor(celula -> editor), chave)){
        anterior = celula;
        celula = celula -> prox;
    }
    
    if (celula == NULL){
        return;
    }
    
    editor = celula -> editor;
    
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
    
    destroiEditor (celula -> editor);
    free(celula);
}

void destroiListaEditor (ListaEditor* lista){
    Celula* celula;
    Celula* aux_cel;
    
    celula = lista -> prim;
    
    while (celula !=NULL){
        aux_cel = celula -> prox;
        destroiEditor(celula -> editor);
        free(celula);
        celula = aux_cel;
    }
    
    free(lista);
}