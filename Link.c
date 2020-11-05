/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.c
 * Author: joao
 * 
 * Created on 1 de Novembro de 2020, 16:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "Link.h"
#include "Pagina.h"

struct link{
    Pagina* pag;
};

Link* iniciaLink(Pagina* pag){
    Link* link = (Link*) malloc (sizeof(Link));
    link -> pag = pag;
    return link;
}

void imprimeTituloLink(Link* link){
    printf("%s", retornaTituloPagina (link -> pag));
}

void imprimeNomeLink(Link* link){
    printf("%s", retornaNomePagina (link -> pag));
}

Pagina* retornaPagLink(Link* link){
    return link -> pag;
}

Link* destroiLink(Link* link){
    free(link);
}