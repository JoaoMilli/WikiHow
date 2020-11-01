/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pagina.c
 * Author: joao
 * 
 * Created on 29 de Outubro de 2020, 19:52
 */


#include "Pagina.h"
#include "Contribuicao.h"
#include "ListaCont.h"
#include "ListaLink.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct pagina{
    char* titulo;
    ListaCont* cont;
    ListaLink* link;
    char* nome;   
};

Pagina* iniciaPagina (char nome[20], char titulo[20]){
    Pagina* pag = (Pagina*) malloc (sizeof(Pagina));
    pag -> nome = strdup(nome);
    pag -> titulo = strdup(titulo);
    pag -> cont = iniciaListaCont();
    pag -> link = iniciaListaLink();
    return pag;
}

void imprimePagina (Pagina* pag){
    
    FILE* file;
    
    char* nome = pag -> nome;
    
    file = fopen (nome, "w");
    
    fprintf(file,"%s\n\n", pag -> titulo);
    fprintf(file,"--> Historico de contribuicoes\n\n");
    
    fclose(file);
    
    imprimeListaContNomes (pag -> cont, nome);
    
    file = fopen (nome, "a");
    
    fprintf(file,"\n\n\n");
    fprintf(file,"--> Textos\n\n");
    
    fclose(file);
    
    imprimeListaCont (pag -> cont, nome);   
}

char* retornaNomePagina (Pagina* pag){
    return pag -> nome;
}

char* retornaTituloPagina (Pagina* pag){
    return pag -> titulo;
}

ListaCont* retornaListaContPag (Pagina* pag){
    return pag -> cont;
}

ListaLink* retornaListaLinkPag (Pagina* pag){
    return pag -> link;
}

char* destroiPagina (Pagina* pag){
    destroiListaCont (pag -> cont);
    destroiListaLink (pag -> link);
    free(pag -> nome);
    free(pag -> titulo);
    free(pag);
}