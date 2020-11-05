/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPag.c
 * Author: joao
 * 
 * Created on 30 de Outubro de 2020, 12:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaPag.h"
#include "Pagina.h"
#include "Link.h"
#include "ListaLink.h"

typedef struct celula Celula;

struct celula{
    Pagina* pag;
    Celula* prox;
};

struct lista_pag{
    Celula* prim;
    Celula* ult;
};

ListaPag* iniciaListaPagina(){
    ListaPag* lista;
    lista = (ListaPag*) malloc (sizeof(ListaPag));
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

Pagina* retornaPagina(ListaPag* lista, char chave[20]){
    Celula* cel;
    
    for(cel=lista -> prim; cel !=NULL; cel = cel-> prox){
        if (!strcmp(chave, retornaTituloPagina (cel -> pag))){
            return cel-> pag;
        }
    }
    return (NULL);
}

void insereListaPag (ListaPag* lista, Pagina* pag){
    Celula* celula;
    celula = (Celula*) malloc (sizeof(Celula));
    celula -> pag = pag;
    if (lista -> ult != NULL) lista -> ult -> prox = celula;
    lista -> ult = celula;
    celula -> prox = NULL;
    
    if(lista -> prim == NULL) lista -> prim = celula;
}

void imprimeListaPag (ListaPag* lista){
    
    Celula* aux_cell;
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        imprimePagina (aux_cell -> pag);
    }
}

void retiraListaPag (ListaPag* lista, char* chave){
    
    Celula* celula = lista -> prim;
    Pagina* pag;
    Celula* anterior = NULL;
    
    
    while (celula != NULL && strcmp(retornaTituloPagina(celula -> pag), chave)){
        anterior = celula;
        celula = celula -> prox;
    }
    
    if (celula == NULL){
        return;
    }
    
    pag = celula -> pag;
    
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
    
    destroiPagina (celula -> pag);
    
    free(celula);
}

void removeLinks(ListaPag* lista, char nome[30]){
    Celula* aux_cell;
    Pagina* pag;
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        if (!strcmp(nome, retornaTituloPagina (aux_cell -> pag))){
            pag = aux_cell -> pag;
            break;
        }
    }
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        retiraPaginaLink (retornaListaLinkPag (aux_cell -> pag), pag);
    }
}

void destroiListaPag (ListaPag* lista){
    
    Celula* celula;
    Celula* aux_cel;
    
    celula = lista -> prim;
    
    while (celula !=NULL){
        aux_cel = celula -> prox;
        destroiPagina (celula -> pag);
        free(celula);
        celula = aux_cel;
    }
    
    free(lista);
}