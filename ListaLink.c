/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaLink.c
 * Author: joao
 * 
 * Created on 1 de Novembro de 2020, 16:35
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link.h"
#include "ListaLink.h"
#include "Pagina.h"

typedef struct celula Celula;

struct celula{
    Link* link;
    Celula* prox;
};

struct lista_link{
    Celula* prim;
    Celula* ult;
};

ListaLink* iniciaListaLink(){
    ListaLink* lista;
    lista = (ListaLink*) malloc (sizeof(ListaLink));
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

void insereListaLink (ListaLink* lista, Link* link){
    Celula* celula;
    celula = (Celula*) malloc (sizeof(Celula));
    celula -> link = link;
    if (lista -> ult != NULL) lista -> ult -> prox = celula;
    lista -> ult = celula;
    celula -> prox = NULL;
    
    if(lista -> prim == NULL) lista -> prim = celula;
}

void imprimeListaLink (ListaLink* lista){
    Celula* aux_cell;
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        imprimeTituloLink(aux_cell -> link);
        printf(" ");
        imprimeNomeLink(aux_cell -> link);
        printf("\n");
    }
}

void retiraListaLink (ListaLink* lista, Link* chave){
    Celula* celula = lista -> prim;
    Link* link;
    Celula* anterior = NULL;
    
    
    while (celula != NULL && celula -> link != link){
        anterior = celula;
        celula = celula -> prox;
    }
    
    if (celula == NULL){
        return;
    }
    
    link = celula -> link;
    
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
    
    destroiLink(celula -> link);
    
    free(celula);
}

void retiraPaginaLink (ListaLink* lista, Pagina* pagina){
    Celula* aux_cell;
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        if (retornaPagLink(aux_cell -> link) == pagina){
            retiraListaLink (lista, aux_cell -> link);
        }
    }
}

Link* retornaLink (ListaLink* lista, char chave[20]){
    Celula* cel;
    
    for(cel=lista -> prim; cel !=NULL; cel = cel-> prox){
        if (!strcmp(chave, retornaTituloPagina (retornaPagLink(cel -> link)))){
            return cel-> link;
        }
    }
}

void destroiListaLink (ListaLink* lista){
    Celula* celula;
    Celula* aux_cel;
    
    celula = lista -> prim;
    
    while (celula !=NULL){
        aux_cel = celula -> prox;
        destroiLink (celula -> link);
        free(celula);
        celula = aux_cel;
    }
    
    free(lista);
}