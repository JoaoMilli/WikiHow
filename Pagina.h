/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pagina.h
 * Author: joao
 *
 * Created on 29 de Outubro de 2020, 19:52
 */

#ifndef PAGINA_H
#define PAGINA_H

#include "ListaCont.h"

typedef struct pagina Pagina;

#include "ListaLink.h"

Pagina* iniciaPagina (char nome[20], char titulo[20]);

void imprimePagina (Pagina* pag);

char* retornaNomePagina (Pagina* pag);

char* retornaTituloPagina (Pagina* pag);

char* destroiPagina (Pagina* pag);

ListaCont* retornaListaContPag (Pagina* pag);

ListaLink* retornaListaLinkPag (Pagina* pag);


#endif /* PAGINA_H */
