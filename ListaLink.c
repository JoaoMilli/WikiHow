#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link.h"
#include "ListaLink.h"
#include "Pagina.h"
#include "ListaPag.h"

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

void imprimeListaLink (ListaLink* lista, char* nome){
    Celula* aux_cell;
    
    FILE* file;
    
    for (aux_cell = lista -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        imprimeTituloLink(aux_cell -> link, nome);
        file = fopen (nome, "a");
        fprintf(file, " ");
        fclose(file);
        imprimeNomeLink(aux_cell -> link, nome);
        file = fopen (nome, "a");
        fprintf(file, "\n");
        fclose(file);
    }
}

void retiraListaLink (ListaLink* lista, Link* chave){
    Celula* celula = lista -> prim;
    Link* link;
    Celula* anterior = NULL;
    
    
    while (celula != NULL && celula -> link != chave){
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

int Caminho (Pagina* p1, Pagina* p2){ 
        
    if (retornaTituloPagina(p1) == retornaTituloPagina(p2)){
        return 1;
    }
    
    ListaPag* visitada;
   
    ListaPag* queue;
    
    ListaLink* lista_link;
    
    Celula* aux_cell;
    
    Pagina* p_aux, *p_aux2, *p_aux3;
    
    visitada = iniciaListaPagina();
    queue = iniciaListaPagina();
            
    insereListaPag (visitada, p1);
    
    lista_link = retornaListaLinkPag(p1);
    
    for (aux_cell = lista_link -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
        if (retornaPagLink(aux_cell -> link) == p2){
            destroiListaPagCelulas (visitada);
            destroiListaPagCelulas (queue);
            return 1;
        }
        insereListaPag(queue, retornaPagLink(aux_cell -> link));
    }       
    while (!vazia(queue)){
        p_aux = retornaPrim(queue);
        insereListaPag(visitada, p_aux);
        retiraListaPagSD (queue, retornaTituloPagina (p_aux));
        lista_link = retornaListaLinkPag(p_aux);
        for (aux_cell = lista_link -> prim; aux_cell != NULL; aux_cell = aux_cell -> prox){
                
            p_aux2 = retornaPagina(visitada, retornaTituloPagina (retornaPagLink(aux_cell -> link)));
            p_aux3 = retornaPagina(queue, retornaTituloPagina (retornaPagLink(aux_cell -> link)));
                
            if (!p_aux2 && !p_aux3){
                if (retornaPagLink(aux_cell -> link) == p2){
                    destroiListaPagCelulas (visitada);
                    destroiListaPagCelulas (queue);
                return 1;
                }
                insereListaPag(queue, retornaPagLink(aux_cell -> link));
            }
        } 
    }
    destroiListaPagCelulas (visitada);
    destroiListaPagCelulas (queue);
    return 0;
}
