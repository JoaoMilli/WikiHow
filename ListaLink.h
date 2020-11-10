/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaLink.h
 * Author: joao
 *
 * Created on 1 de Novembro de 2020, 16:35
 */

#ifndef LISTALINK_H
#define LISTALINK_H

#include "Link.h"
#include "Pagina.h"

typedef struct lista_link ListaLink;

ListaLink* iniciaListaLink();

Link* retornaLink (ListaLink* lista, char chave[20]);

void insereListaLink (ListaLink* lista, Link* link);

void imprimeListaLink (ListaLink* lista, char* nome);

void retiraListaLink (ListaLink* lista, Link* chave);

void destroiListaLink (ListaLink* lista);

void retiraPaginaLink (ListaLink* lista, Pagina* pagina);

#endif /* LISTALINK_H */
